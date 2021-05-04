/*
 * Copyright (C) 2011 Daniel Bates (dbates@intudata.com). All Rights Reserved.
 * Copyright (c) 2012 Google, inc.  All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Google Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "TextEncoding.h"
#include <wtf/ASCIICType.h>
#include <wtf/Assertions.h>
#include <wtf/text/StringBuilder.h>

namespace WebCore {

// See <http://en.wikipedia.org/wiki/Percent-encoding#Non-standard_implementations>.
struct Unicode16BitEscapeSequence {
    enum { sequenceSize = 6 }; // e.g. %u26C4
    static size_t findInString(StringView string, size_t startPosition) { return string.find(StringView("%u"), startPosition); }
    static size_t findEndOfRun(StringView string, size_t startPosition, size_t endPosition)
    {
        size_t runEnd = startPosition;
        while (endPosition - runEnd >= sequenceSize && string[runEnd] == '%' && string[runEnd + 1] == 'u'
               && isASCIIHexDigit(string[runEnd + 2]) && isASCIIHexDigit(string[runEnd + 3])
               && isASCIIHexDigit(string[runEnd + 4]) && isASCIIHexDigit(string[runEnd + 5])) {
            runEnd += sequenceSize;
        }
        return runEnd;
    }
    static String decodeRun(StringView run, const TextEncoding&)
    {
        // Each %u-escape sequence represents a UTF-16 code unit.
        // See <http://www.w3.org/International/iri-edit/draft-duerst-iri.html#anchor29>.
        // For 16-bit escape sequences, we know that findEndOfRun() has given us a contiguous run of sequences
        // without any intervening characters, so decode the run without additional checks.
        auto numberOfSequences = run.length() / sequenceSize;
        StringBuilder builder;
        builder.reserveCapacity(numberOfSequences);
        while (numberOfSequences--) {
            UChar codeUnit = (toASCIIHexValue(run[2]) << 12) | (toASCIIHexValue(run[3]) << 8) | (toASCIIHexValue(run[4]) << 4) | toASCIIHexValue(run[5]);
            builder.append(codeUnit);
            run = run.substring(sequenceSize);
        }
        return builder.toString();
    }
};

struct URLEscapeSequence {
    enum { sequenceSize = 3 }; // e.g. %41
    static size_t findInString(StringView string, size_t startPosition) { return string.find('%', startPosition); }
    static size_t findEndOfRun(StringView string, size_t startPosition, size_t endPosition)
    {
        // Make the simplifying assumption that supported encodings may have up to two unescaped characters
        // in the range 0x40 - 0x7F as the trailing bytes of their sequences which need to be passed into the
        // decoder as part of the run. In other words, we end the run at the first value outside of the
        // 0x40 - 0x7F range, after two values in this range, or at a %-sign that does not introduce a valid
        // escape sequence.
        size_t runEnd = startPosition;
        int numberOfTrailingCharacters = 0;
        while (runEnd < endPosition) {
            if (string[runEnd] == '%') {
                if (endPosition - runEnd >= sequenceSize && isASCIIHexDigit(string[runEnd + 1]) && isASCIIHexDigit(string[runEnd + 2])) {
                    runEnd += sequenceSize;
                    numberOfTrailingCharacters = 0;
                } else
                    break;
            } else if (string[runEnd] >= 0x40 && string[runEnd] <= 0x7F && numberOfTrailingCharacters < 2) {
                runEnd += 1;
                numberOfTrailingCharacters += 1;
            } else
                break;
        }
        return runEnd;
    }

    static Vector<char, 512> decodeRun(StringView run)
    {
        // For URL escape sequences, we know that findEndOfRun() has given us a run where every %-sign introduces
        // a valid escape sequence, but there may be characters between the sequences.
        Vector<char, 512> buffer;
        buffer.grow(run.length()); // Unescaping hex sequences only makes the length smaller.
        char* p = buffer.data();
        while (!run.isEmpty()) {
            if (run[0] == '%') {
                *p++ = (toASCIIHexValue(run[1]) << 4) | toASCIIHexValue(run[2]);
                run = run.substring(sequenceSize);
            } else {
                *p++ = run[0];
                run = run.substring(1);
            }
        }
        ASSERT(buffer.size() >= static_cast<size_t>(p - buffer.data())); // Prove buffer not overrun.
        buffer.shrink(p - buffer.data());
        return buffer;
    }

    static String decodeRun(StringView run, const TextEncoding& encoding)
    {
        auto buffer = decodeRun(run);
        if (!encoding.isValid())
            return UTF8Encoding().decode(buffer.data(), buffer.size());
        return encoding.decode(buffer.data(), buffer.size());
    }
};

template<typename EscapeSequence>
String decodeEscapeSequences(StringView string, const TextEncoding& encoding)
{
    StringBuilder result;
    size_t length = string.length();
    size_t decodedPosition = 0;
    size_t searchPosition = 0;
    size_t encodedRunPosition;
    while ((encodedRunPosition = EscapeSequence::findInString(string, searchPosition)) != notFound) {
        size_t encodedRunEnd = EscapeSequence::findEndOfRun(string, encodedRunPosition, length);
        searchPosition = encodedRunEnd;
        if (encodedRunEnd == encodedRunPosition) {
            ++searchPosition;
            continue;
        }

        String decoded = EscapeSequence::decodeRun(string.substring(encodedRunPosition, encodedRunEnd - encodedRunPosition), encoding);
        if (decoded.isEmpty())
            continue;

        result.append(string.substring(decodedPosition, encodedRunPosition - decodedPosition));
        result.append(decoded);
        decodedPosition = encodedRunEnd;
    }
    result.append(string.substring(decodedPosition, length - decodedPosition));
    return result.toString();
}

inline Vector<char> decodeURLEscapeSequencesAsData(StringView string, const TextEncoding& encoding)
{
    ASSERT(encoding.isValid());

    Vector<char> result;
    size_t decodedPosition = 0;
    size_t searchPosition = 0;
    while (true) {
        size_t encodedRunPosition = URLEscapeSequence::findInString(string, searchPosition);
        size_t encodedRunEnd = 0;
        if (encodedRunPosition != notFound) {
            encodedRunEnd = URLEscapeSequence::findEndOfRun(string, encodedRunPosition, string.length());
            searchPosition = encodedRunEnd;
            if (encodedRunEnd == encodedRunPosition) {
                ++searchPosition;
                continue;
            }
        }

        // Strings are encoded as requested.
        result.appendVector(encoding.encode(string.substring(decodedPosition, encodedRunPosition - decodedPosition), UnencodableHandling::URLEncodedEntities));

        if (encodedRunPosition == notFound)
            return result;
        
        // Bytes go through as-is.
        auto decodedEscapeSequence = URLEscapeSequence::decodeRun(string.substring(encodedRunPosition, encodedRunEnd - encodedRunPosition));
        ASSERT(!decodedEscapeSequence.isEmpty());
        result.appendVector(decodedEscapeSequence);

        decodedPosition = encodedRunEnd;
    }
}

} // namespace WebCore

