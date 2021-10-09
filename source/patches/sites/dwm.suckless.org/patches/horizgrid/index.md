horizontal grid
===============

Description
-----------
This patch is a variant of [gaplessgrid](../gaplessgrid/). It arranges
windows in a grid pattern in which every window is roughly the same size,
adjusted such that there are no gaps. However, this layout arranges the windows
in a horizontal grid, rather than a vertical grid.

Horizontal Grid Layout
----------------------
	horizgrid     (###)
	+--------+--------+
	|        |        |
	|        |        |
	+-----+--+--+-----+
	|     |     |     |
	|     |     |     |
	+-----+-----+-----+

	gapless_grid
	+--------+--------+
	|        |        |
	|        +--------+
	+--------+        |
	|        +--------+
	|        |        |
	+--------+--------+

Download
--------
* [dwm-horizgrid-6.1.diff](dwm-horizgrid-6.1.diff) (20160108)

Authors
-------
* Marshall Mason - `<marshallmason2@gmail.com>`
