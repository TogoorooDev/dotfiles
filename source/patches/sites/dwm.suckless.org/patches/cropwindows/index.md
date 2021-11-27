cropwindows
===========

Description
-----------
Create cropped views of existing windows to display only part of them,
typically to reclaim screen space from badly framed videos or programs and
websites with terrible designs.

Usage
-----
Look at the changes made to `config.def.h`: pass `1` to `resizemouse` to create
a cropped window and to `movemouse` to move the underlying window in the crop.

	{ ClkClientWin, MODKEY|ShiftMask, Button1, movemouse,   {.i = 1} },
	{ ClkClientWin, MODKEY|ShiftMask, Button3, resizemouse, {.i = 1} },

Cropped windows are always in the floating state, use `togglefloating`
(`mod-shift-space` by default) to uncrop and restore the underlying window to
its original size and state.

Download
--------
* [dwm-cropwindows-20170709-ceac8c9.diff](dwm-cropwindows-20170709-ceac8c9.diff)

Notes
-----
* tested with a limited set of clients and use-cases, some X11 events are
  probably not passed or handled correctly, report bugs if you see any,
* known bug: if you crop a window at the same time another window is unmapped,
  there is a chance that dwm will lose control of the window you are cropping
  and your only option will be to kill it (this is a pain to fix properly),
* improvements: investigate `xextproto/shape` for non-rectangular crops!

Authors
-------
* Ivan Delalande <colona@ycc.fr>
