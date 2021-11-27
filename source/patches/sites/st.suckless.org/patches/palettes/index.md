color\_schemes
==============

Description
-----------
This patch allows you to work with 16 color palettes and change them on the
fly.

Instructions
------------
The patch changes the “config.def.h”.
Delete your “config.h” or change it manually if you use a custom one.

Notes
-----
It uses the following shortcuts :

	Shortcut shortcuts[] = {
		...
		{ TERMMOD, XK_F1, setpalette, {.i = 0} },
		{ TERMMOD, XK_F2, setpalette, {.i = 1} },
		{ TERMMOD, XK_F3, setpalette, {.i = 2} },
		{ TERMMOD, XK_F4, setpalette, {.i = 3} },
		{ TERMMOD, XK_F5, setpalette, {.i = 4} },
		{ TERMMOD, XK_F6, setpalette, {.i = 5} },
		{ TERMMOD, XK_F7, setpalette, {.i = 6} },
		{ TERMMOD, XK_F8, setpalette, {.i = 7} },
		{ TERMMOD, XK_F9, setpalette, {.i = 8} },
	};

Download
--------
* [st-color\_schemes-0.8.1.diff](st-color_schemes-0.8.1.diff)


Authors
-------
* Tonton Couillon - <la dot luge at free dot fr>
