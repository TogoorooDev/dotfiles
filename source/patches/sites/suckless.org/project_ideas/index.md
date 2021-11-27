Project ideas
=============
Please read our [philosophy](/philosophy) for background information.

Peer review
-----------
The suckless.org community will act as a rigid reviewer of the progress.

General ideas
-------------
Our project ideas in general intend to focus on our innovative development
environment from bare hardware to the graphical interface.

* Idiomatic interfaces for developers (such as more advanced concepts for mail
  clients, messaging clients, music players, text editors).
* Simple protocol interfaces for developers.
* General userland enhancements to UNIX-like operating systems.
* Foundations of a new windowing system for UNIX-like operating systems.
* Improvements to our existing software projects and infrastructure.
* Replacements of bloated existing software and libraries in a suckless way.


Current small tasks
-------------------
* Write a gopher back-end using build-page.c:
  <https://git.suckless.org/sites/file/build-page.c.html>
  This should use the geomyidae gopher server and the gph output format.
  Difficulty: medium-rare.
* Fix broken patches on the wiki. Difficulty: trivial-medium.
* Fix typos and formatting errors on the wiki. Difficulty: trivial.


Concrete ideas
--------------
The listed ideas generally require good knowledge of C and experience with
UNIX-like operating systems. The difficulty ranges from medium to high.


### Suckless font rendering library

There is libdrw in suckless now, which still uses xft and fontconfig.
Fontconfig and xft are ugly and require too much internal knowledge to be
useful. The next logical layer evolved as pango and cairo. Both of course added
HTML formatting and vector drawing. This is not needed to simply draw some text
somewhere. And this is what a suckless font rendering library should do: Give
it a font string and render at some position the given font without having to
care about font specifics.

[Some work](https://git.ekleog.org/leo/dtext) has already been done to replace
libXft and Fontconfig. Real-world testing is however still needed.

A simple solution is [Scalable Screen Font](https://gitlab.com/bztsrc/scalable-font2),
which is a dependency-free, single ANSI C89 header file that can render bitmap,
pixmap and vector fonts using the same API. Uses a very efficient font format and
includes a multiplatform command line tool to convert virtually all font files
into .sfn files. Comparable to professional font rendering engines, supports
UNICODE, scaling, anti-aliasing, alpha-blending, kerning, ligatures etc.

***Requirements:*** C knowledge, some X11 knowledge and of course knowledge
about the font formats and how to handle them.


### Write ld wrapper or replacement for static linking

The GNU autotools such as automake and autoconf are completely unusable in
non-chroot'ed cross-compile environments and often completely fail to produce
statically linked libraries or executables. Also they are extremely slow and
bloated.

The stali build system is not using autotools for good reason, however many
UNIX/Linux open source packages do. To create statically linked libraries out
of the ld arguments we need an ld wrapper or re-implementation that creates
static libraries or executables. This would enable us to build static libraries
and executables out of any automake generated makefiles without the need to
write make replacements or patching the build system of a particular package.

The ld wrapper needs to be extended to also link against uclibc first and if
that fails to fallback to glibc, in order to produce smaller executables in the
general case.

***Requirements:*** Good C/UNIX knowledge is essential, knowledge about
linking/linker internals are desirable.


### Write a decent mailing list Web archive system

All web archive systems such as hypermail, pipermail, etc. have plenty
drawbacks and are quite out-dated. This task requires to write a completely new
web mailing list archiving tool that follows the thread view concepts found in
the mutt MUA and which is designed with low footprint and efficiency in mind.

We expect this tool as a stand-alone UNIX tool written in C or shell. To get
started you could use [Dovecot](http://dovecot.org/) to produce a sanitized
structure:

	printf "1 select inbox\n2 thread references us-ascii all\n3 fetch 1:*
	envelope\n4 logout\n" |
	/usr/local/libexec/dovecot/imap  2>/dev/null

* <http://www.codinghorror.com/blog/2012/12/web-discussions-flat-by-design.html>

***Requirements:*** Good C/Shell/HTML knowledge would be desirable. Must not
use Javascript.


### Write cookie handler for surf

The biggest disadvantage of [surf](//surf.suckless.org) is sloppy cookie
handling. libwebkit and libsoup (which are used for HTTP) were never designed
to run in multiple processes simultaneously.

This task requires writing a new cookie handler in surf which:

* creates a nice human-readable cookie file
* is able to run in multiple concurrent processes

***Requirements:*** Good knowledge of C and POSIX file locking. Basic knowledge
of GTK and its other evil friends.


### Gopher services

Gopher is a sane protocol which has hierarchy in its design. It allows the
abstraction of a mass of information in a filesystem. The goal of this meta
project is to find ideas how to implement gopher services to easily access the
web and new information.

See the
[protocol](https://en.wikipedia.org/wiki/Gopher_%28protocol%29#Protocol) for
how easy it is to write a `menu`, which can be seen as a directory.

* [gopherproject.org](http://www.gopherproject.org)
* [gopher proxy](http://gopher.floodgap.com/gopher/)
* [Gopher wikipedia article](https://en.wikipedia.org/wiki/Gopher_%28protocol%29)
* [geomyidae](http://git.r-36.net/geomyidae/)

Anyone creating a gopher interface to suckless.org will get a bonus.

***Requirements:*** Just some shell scripting and a way to setup a gopher
daemon is required. Everyone can do this.


### A sane backend for surf

There is dillo, netsurf and abaco which implement HTML. The problem is
Javascript and extensions to replace webkit as the big dependency hell for web
rendering in surf.

If you prepare to work on this project, plan ahead in recruiting more
developers. You will need them.

***Requirements:*** Very good C knowledge, a very good knowledge in web
standards and how to strip them down to the suckless level. ***Difficulty
level:*** Probably impossible.
