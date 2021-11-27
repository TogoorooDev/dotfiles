alpha
=====

[![Screenshot](dwm-alpha.png)](dwm-alpha.png)

Description
-----------
Allow dwm to have translucent bars, while keeping all the text on it opaque,
just like the [alpha-patch for st](//st.suckless.org/patches/alpha/).

### Fix transparent borders

By default dwm might make windows' borders transparent when using
composit window manager (e.g. xcompmgr, picom).  Alpha patch allows to
make borders opaque.

If all you want is to make borders opaque, you don't care about
statusbar opacity and/or have problems applying alpha patch, then you
might use fixborders patch instead.

Download
--------
* [dwm-alpha-6.1.diff](dwm-alpha-6.1.diff)
* [dwm-alpha-20180613-b69c870.diff](dwm-alpha-20180613-b69c870.diff)
* [dwm-alpha-20201019-61bb8b2.diff](dwm-alpha-20201019-61bb8b2.diff)
* [dwm-fixborders-6.2.diff](dwm-fixborders-6.2.diff)

Authors
-------
* Eon S. Jeon - <esjeon@hyunmu.am>
* Laslo Hunhold - <dev@frign.de> (6.1 port)
* Thomas Oltmann - <thomas.oltmann.hhg@gmail.com> (20180613-b69c870 port)
* Petrus Karell - <pk@petruskarell.fi> (20201019-61bb8b2 port)
* Jakub Leszczak - <szatan@gecc.xyz> (fixborders patch)
