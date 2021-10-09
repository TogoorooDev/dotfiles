resetlayout
===========

Description
-----------

Resets the layout and mfact if there is only one client visible.

This applies cleanly to vanilla dwm, but is mostly only useful alongside the
[pertag](../pertag/) patch, since otherwise all layouts and mfacts will be
reset.

You can also set a binding to trigger this on demand, see the new call to
resetlayout in config.def.h.

Download
--------
* [dwm-resetlayout-6.2.diff](dwm-resetlayout-6.2.diff)
* [dwm-resetlayout-20200420-c82db69.diff](dwm-resetlayout-20200420-c82db69.diff)

Authors
-------
* Chris Down - <chris@chrisdown.name>
* Jack Bird - <jack.bird@dur.ac.uk>
