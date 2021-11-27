maximize
========

Description
-----------
These patch provide helper functions for maximizing, horizontally and
vertically, floating windows using keybindings.

Usage
-----
Insert the bindings into the keys list. Here is an example:

	{ MODKEY|ControlMask|ShiftMask, XK_h,           togglehorizontalmax, NULL },
	{ MODKEY|ControlMask|ShiftMask, XK_l,           togglehorizontalmax, NULL },
	{ MODKEY|ControlMask|ShiftMask, XK_j,           toggleverticalmax,   NULL },
	{ MODKEY|ControlMask|ShiftMask, XK_k,           toggleverticalmax,   NULL },
	{ MODKEY|ControlMask,           XK_m,           togglemaximize,      {0} },

Download
--------
* [dwm-maximize\_vert\_horz-20160731-56a31dc.diff](dwm-maximize_vert_horz-20160731-56a31dc.diff)
* [dwm-maximize\_vert\_horz-6.1.diff](dwm-maximize_vert_horz-6.1.diff) (Unclean patch)
* [dwm-maximize\_vert\_horz-6.0.diff](dwm-maximize_vert_horz-6.0.diff)

Author
------
* Jan Christoph Ebersbach - <jceb@e-jc.de>
