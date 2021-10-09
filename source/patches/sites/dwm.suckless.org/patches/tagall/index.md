tag all
=======

Description
-----------
Shortcut to move all (floating) windows from one tag to another.

Download
--------
* [dwm-tagall-20160731-56a31dc.diff](dwm-tagall-20160731-56a31dc.diff)
* [dwm-tagall-6.1.diff](dwm-tagall-6.1.diff) (1058b) (20140209)
* [dwm-tagall-6.0.diff](dwm-tagall-6.0.diff) (988b) (20120406)

Configuration
-------------
* MODKEY+Shift+F1 moves all floating windows of the current tag to tag 1

	{ MODKEY|ShiftMask,     XK_F1,      tagall,        {.v = "F1"} }, \
	...
	{ MODKEY|ShiftMask,     XK_F9,      tagall,        {.v = "F9"} }, \

* MODKEY+Shift+F1 moves all windows of the current tag to tag 1

	{ MODKEY|ShiftMask,     XK_F1,      tagall,        {.v = "1"} }, \
	...
	{ MODKEY|ShiftMask,     XK_F9,      tagall,        {.v = "9"} }, \

Author
------
* Jan Christoph Ebersbach - <jceb@e-jc.de>
