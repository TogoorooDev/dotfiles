/*
 * Copyright (C) 2021 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "RemoteRemoteCommandListenerProxy.h"

#if ENABLE(GPU_PROCESS)

#include "GPUConnectionToWebProcess.h"
#include "RemoteRemoteCommandListenerMessages.h"

namespace WebKit {

using namespace WebCore;

RemoteRemoteCommandListenerProxy::RemoteRemoteCommandListenerProxy(GPUConnectionToWebProcess& gpuConnection, RemoteRemoteCommandListenerIdentifier&& identifier)
    : m_gpuConnection(makeWeakPtr(gpuConnection))
    , m_identifier(WTFMove(identifier))
    , m_listener(WebCore::RemoteCommandListener::create(*this))
{
}

RemoteRemoteCommandListenerProxy::~RemoteRemoteCommandListenerProxy() = default;

void RemoteRemoteCommandListenerProxy::didReceiveRemoteControlCommand(PlatformMediaSession::RemoteControlCommandType command, const PlatformMediaSession::RemoteCommandArgument& argument)
{
    if (!m_gpuConnection)
        return;

    m_gpuConnection->connection().send(Messages::RemoteRemoteCommandListener::DidReceiveRemoteControlCommand(command, argument), m_identifier);
}

void RemoteRemoteCommandListenerProxy::updateSupportedCommands(bool supportsSeeking)
{
    m_listener->setSupportsSeeking(supportsSeeking);
    m_listener->updateSupportedCommands();
}

}

#endif
