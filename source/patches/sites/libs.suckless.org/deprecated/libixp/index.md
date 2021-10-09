LIBIXP
======
`libixp` is a stand-alone client/server [9P](http://9p.cat-v.org/) library
including `ixpc` client. It consists of less than 2000 lines of code (including
`ixpc`).

`libixp`'s server API is based heavily on that of [Plan
9](http://cm.bell-labs.com/plan9)'s
[`lib9p`](http://man.cat-v.org/plan_9/2/9p), and the two libraries export
virtually identical data structures. There are a few notable differences
between the two, however:

* `libixp` multiplexes connections internally, while on `Plan 9`, the kernel
  performs this task, and in [plan9port](http://swtch.com/plan9port/), a separate
  process is spawned to do so. Despite this divergence, the user of the library
  will not notice any difference in behavior, except that there may be duplicate
  `tag` and `fid` numbers between different connections. This issue is of little
  relevance, however, as the library handles the task of mapping `fid`s and
  `tag`s to arbitrary pointers and `P9Req` structs.

* `libixp` is released under a lenient MIT-style license.

* `libixp` lacks `lib9p`'s file trees.

* Unlike `plan9port`'s `lib9p`, `libixp` is POSIX based, and should compile
  without specialized libraries on nearly any POSIX system.

Download
--------
* [libixp-0.5](//dl.suckless.org/libs/libixp-0.5.tar.gz)

