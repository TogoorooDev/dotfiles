9base
=====
9base is a port of various original Plan 9 tools for Unix, based on
[plan9port](http://swtch.com/plan9port/).

It currently contains the following original (no source changes) shell commands
from Plan 9 for Unix:

* ascii
* awk
* basename
* bc
* cal
* cat
* cleanname
* cmp
* date
* dc
* du
* dd
* diff
* echo
* ed
* factor
* fortune
* fmt
* freq
* getflags
* grep
* hoc
* join
* look
* ls
* mk
* mkdir
* mtime
* pbd
* primes
* rc
* read
* sam
* sha1sum
* sed
* seq
* sleep
* sort
* split
* strings
* tail
* tee
* test
* touch
* tr
* troff
* unicode
* uniq
* unutf

It also contains the Plan 9 libc, libbio, libregexp, libfmt and libutf. The
overall SLOC is about 66kSLOC, so this userland + all libs is much smaller
than, e.g. bash (duh!).

Download
--------
* [9base-6](//dl.suckless.org/tools/9base-6.tar.gz) (20100604)
* git clone https://git.suckless.org/9base

Usage
-----
9base can be used to run [werc](http://werc.cat-v.org) instead of the full
blown [plan9port](http://swtch.com/plan9port).
