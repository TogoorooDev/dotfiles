Pango
=====

Description
-----------
This relatively simple patch adds pango support for the status bar. This not only adds
TrueType font support but also opens a couple of interesting possibilities that are
not possible under barebone xft:

**Simple markup** for status messages (optional in 6.0 patch, enable/disable it in your
config.h) using
[pango markup](https://developer.gnome.org/pygtk/stable/pango-markup-language.html). So
you can format your status messages specifying fg/bg colors, sizes,
sub/superscripts, underline, emphasis, bold, etc. You can do dynamic font
switching, also! To play safe with the rest of the status bar, markup support
is restricted to the status message area over which you have direct control.

**Fallback fonts**, so you can use -for example- some set of iconic fonts as
your second family: "DejaVu Sans, Icons 8" (see below). There are tons of
monochromatic nice looking TTF icons around the web these days as webfonts are
becoming more and more popular. Notice that you can also use the more powerful
font switching enabled by pango markup to achieve the same goal. Also don't be
mislead by the fact that fontconfig understands descriptors like "DejaVu Sans,
Icons-8" or even font sequences defined as alias in your fonts.conf. xft will
pick one font once and for all, not on a char-by-char basis.

The [Icons family](https://aur.archlinux.org/packages/ttf-font-icons/) is a
non-overlapping merge of Awesome and Ionicons fonts I've made for my statusbar.

In the latest patch (20200428 - which is after version 6.2) there are a lot of changes to
drw.c/h code base (maybe there is a better way of doing things, but it works
as it is).

The last patch fixes some vertical alignment issues which were obvious only for CJK fonts.

Download
--------
* [dwm-pango-20201020-519f869.diff](dwm-pango-20201020-519f869.diff)
* [dwm-pango-20200428-f09418b.diff](dwm-pango-20200428-f09418b.diff)
* [dwm-pango-6.0.diff](dwm-pango-6.0.diff)

Author
------
* Carlos Pita (memeplex) <carlosjosepita@gmail.com>
* Marius Iacob (themariusus) <themariusus@gmail.com>
