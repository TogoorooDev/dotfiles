flextile layout
===============

Description
-----------
This patch replaces the `tile` layout with a more flexible version. The
features include the following:

* tile like the original version (left single master, right stack)
* left/right/top/bottom n-master, right/left/bottom/top/no stack/deck (deck is
  like `monocle` in the stack area)
* per-tag configuration

It therefore provides the following additional possibilities:

* `tile` for left-handed people
* compare multiple files with one other each at a time without switching
  between views

The patch incorporates and expands the following patches:

* bottom stack (`bstack` and `bstackhoriz`)
* nmaster
* pertag

Configuration
-------------
1. Download the patch and apply it according to the
   [general instructions](../).

2. Transfer the changes made by the patch in `config.def.h` to your `config.h`,
   if needed.

	/* tagging */
	...
	/* include(s) depending on the tags array */
	#include "flextile.h"

	/* layout(s) */
	static const int layoutaxis[] = {
		1,    /* layout axis: 1 = x, 2 = y; negative values mirror the layout, setting the master area to the right / bottom instead of left / top */
		2,    /* master axis: 1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle) */
		2,    /* stack axis:  1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle) */
	};
	static const unsigned int mastersplit = 1;	/* number of tiled clients in the master area */

	static Key keys[] = {
    ...
		{ MODKEY,                       XK_i,      shiftmastersplit, {.i = +1} },   /* increase the number of tiled clients in the master area */
		{ MODKEY,                       XK_d,      shiftmastersplit, {.i = -1} },   /* reduce the number of tiled clients in the master area */
	...
		{ MODKEY|ControlMask,           XK_t,      rotatelayoutaxis, {.i = 0} },    /* 0 = layout axis */
		{ MODKEY|ControlMask,           XK_Tab,    rotatelayoutaxis, {.i = 1} },    /* 1 = master axis */
		{ MODKEY|ControlMask|ShiftMask, XK_Tab,    rotatelayoutaxis, {.i = 2} },    /* 2 = stack axis */
		{ MODKEY|ControlMask,           XK_Return, mirrorlayout,     {0} },


Usage
-----
With the default configuration (see above) the original tile layout is
emulated. You can change the layout by adjusting the four parameters `layout
axis`, `master axis`, `stack axis` and `master split` (description see above)
by pressing the appropriate keys.

The original `tile` layout is only available by setting the above parameters,
but not as a discrete layout; the `monocle` layout is still available by
pressing `ALT+m` (in the default configuration).

Download
--------
* [dwm-flextile-20210722-138b405.diff](dwm-flextile-20210722-138b405.diff)
* [dwm-flextile-5.8.2.diff](dwm-flextile-5.8.2.diff)
* [dwm-flextile-5.8.1.diff](dwm-flextile-5.8.1.diff)

Authors
-------
* joten (at) freenet (dot) de
* mail at pascal-wittmann dot de
* Max Schillinger - <maxschillinger@web.de> (6.2 port)
