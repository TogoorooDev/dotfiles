Stuff that sucks
================
See the [philosophy](//suckless.org/philosophy) page about what applies
to this page.

Bigger topics that suck: [systemd](//suckless.org/sucks/systemd),
[the web](//suckless.org/sucks/web)

Libraries
---------
These libraries are broken/considered harmful and should not be used
if it's possible to avoid them. If you use them, consider looking for
alternatives.

* [glib](http://library.gnome.org/devel/glib/) - implements C++ STL on top of C
  (because C++ sucks so much, let's reinvent it!), adding lots of useless data
  types for ["portability" and "readability"
  reasons](http://library.gnome.org/devel/glib/unstable/glib-Basic-Types.html).
  even worse, it is not possible to write robust applications using glib, since
  it [aborts in out-of-memory situations](https://bugzilla.gnome.org/show_bug.cgi?id=674446).
  glib usage is required to write gtk+ and gnome applications, but is also used when common
  functionality is needed (e.g. hashlists, base64 decoder, etc). it is not suited
  at all for static linking due to its huge size and the authors explicitly state
  that ["static linking is not supported"](https://bugzilla.gnome.org/show_bug.cgi?id=768215#c16).

  Alternatives: [libmowgli](https://github.com/atheme/libmowgli-2),
  [libulz](https://github.com/rofl0r/libulz),
  BSD [queue.h](https://man.openbsd.org/queue)/[tree.h](https://man.openbsd.org/tree) macros.

* [GMP](http://gmplib.org/) - GNU's bignum/arbitrary precision
  library. Quite bloated, slow and [calls abort() on failed
  malloc](https://gmplib.org/repo/gmp/file/tip/memory.c#l105)

  Alternatives: [libtommath](http://www.libtom.net/LibTomMath/),
  [TomsFastMath](http://www.libtom.net/TomsFastMath/),
  [imath](https://github.com/creachadair/imath),
  [libzahl](//libs.suckless.org/libzahl) (WIP),
  [hebimath](https://github.com/suiginsoft/hebimath) (WIP)

Build Systems
-------------
* [cmake](http://www.cmake.org/) (written in C++) - so huge and bloated,
  compilation takes longer than compiling GCC (!). It's not even possible
  to create freestanding Makefiles, since the generated Makefiles call
  back into the cmake binary itself. Usage of cmake requires learning a
  new custom scripting language with very limited expressiveness. Its
  major selling point is the existence of a clicky-click GUI for windows
  users.
* [waf](https://code.google.com/p/waf/) and
  [scons](http://www.scons.org/) (both written in Python) - waf code is
  dropped into the compilee's build tree, so it does not benefit from
  updated versions and bugfixes.

As these build systems are often used to compile C programs, one has to
set up a C++ compiler or Python interpreter respectively just in order
to be able to build some C code.

Alternatives:
[make](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/make.html),
[mk](http://doc.cat-v.org/plan_9/4th_edition/papers/mk)

Version Control Systems
-----------------------
* [subversion](https://subversion.apache.org/) - Teaches developers to
  think of version control in a harmful and terrible way, centralized,
  ugly code, conceptionally broken in a lot of terms. "Centralized" is
  said to be one of the main benefits for "enterprise" applications,
  however, there is no benefit at all compared to decentralized version
  control systems like git. There is no copy-on-write, branching
  essentially will create a 1:1 copy of the full tree you have under
  version control, making feature-branches and temporary changes to your
  code a painful mess. It is slow, encourages people to come up with weird
  workarounds just to get their work done, and the only thing enterprisey
  about it is that it just sucks.

Programs
--------
There are many broken X programs. Go bug the developers of these
broken programs to fix them. Here are some of the main causes of this
brokenness:

* The program **assumes a specific window management model**,
  e.g. assumes you are using a WIMP-window manager like those
  found in KDE or Gnome. This assumption breaks the [ICCCM
  conventions](http://tronche.com/gui/x/icccm/).
* The application uses a **fixed size** - this limitation does not fit
  into the world of tiling window managers very well, and can also be seen
  as breaking the ICCCM conventions, because a fixed sized window assumes
  a specific window management model as well (though the ICCCM does not
  forbid fixed-size windows). In any case, the ICCCM requests that clients
  accept any size the window manager proposes to them.
* The program is based on strange **non-standard window manager
  hints** that only work properly with a window manager supporting these
  extensions - this simply breaks the ICCCM as well. E.g. trash icon
  programs.
* The program does not conform to ICCCM due to some **missing or
  improperly set hints**.

If you still need some program which expects a floating WM, use it in
floating mode.

Documentation
-------------
Somewhen GNU tried to make the world a bit more miserable by inventing
[texinfo](https://www.gnu.org/software/texinfo/). The result is that
in 2019 man pages are still used and the documentation of GNU tools
requires you to run `info $application`. The info browser is awkward and
unintuitive and the reason why no one gets further than finding 'q' to
quit it.

Look at GNU tools how to not handle documentation.

Talking about the suck in enforced HTML documentation, which forces
you to open up a 1 Gb of RAM wasting web browser, just to see some
eye-candy, which could have been described in the source with some easy
way to jump to that line in the source code, is not worth the time.

The suckless way is to have a short usage and a descriptive manpage. The
complete details are in the source.

Alternatives: roff, [mdoc](https://mandoc.bsd.lv/).

C Compilers
-----------
* [GCC](http://gcc.gnu.org/): as of 2016 it is now written in C++ and so
  complete suck. Why can't a compiler just be a simple binary doing its work
  instead of adding path dependencies deep into the system?
* [Clang](http://clang.llvm.org/) is written in C++. If you don't
  believe that it sucks, try to build clang by hand.

Alternatives: see the Compilers section of the [/rocks/] page.

See also
--------
The [list of harmful software](http://harmful.cat-v.org/software/) at
[cat-v.org](http://cat-v.org).
