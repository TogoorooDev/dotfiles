gapless grid layout
===================

Description
-----------
This patch is an altered [gridmode](../gridmode) layout for dwm, which arranges
the windows in a grid. Instead of using a regular grid, which might leave empty
cells when there are not enough windows to fill the grid, it adjusts the number
of windows in the first few columns to avoid empty cells.

Usage
-----
Download `gaplessgrid.c` and add the gapless layout to your `config.h`:

	#include "gaplessgrid.c"

	static const Layout layouts[] = {
		/* symbol     arrange function */
		{ "###",      gaplessgrid },
	...

	static Key keys[] = {
		/* modifier                     key        function        argument */
		{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[0] } },
	...

Download
--------
* [dwm-gaplessgrid-20160731-56a31dc.diff](dwm-gaplessgrid-20160731-56a31dc.diff)
* [dwm-gaplessgrid-6.1.diff](dwm-gaplessgrid-6.1.diff) (20140209)
* [gaplessgrid.c](gaplessgrid.c) (dwm 5.6.1) (20090908)
* [dwm-r1437-gaplessgrid.diff](dwm-r1437-gaplessgrid.diff) (20090704)
* [dwm-5.2-gaplessgrid.diff](dwm-5.2-gaplessgrid.diff) (20081020)
