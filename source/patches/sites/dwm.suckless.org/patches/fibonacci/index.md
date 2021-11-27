fibonacci layouts
=================

Description
-----------
This patch adds two new layouts (`spiral` and `dwindle`) that arranges all
windows in Fibonacci tiles: The first window uses half the screen, the second
the half of the remainder, etc. ASCII art and a real screenshot of the spiral
arrangement can be seen below.

	+-----------+-----------+  +-----------+-----------+
	|           |           |  |           |           |
	|           |     2     |  |           |     2     |
	|           |           |  |           |           |
	|     1     +--+--+-----+  |     1     +-----+-----+
	|           | 5|-.|     |  |           |     |  4  |
	|           +--+--+  3  |  |           |  3  +--+--+
	|           |  4  |     |  |           |     | 5|-.|
	+-----------+-----+-----+  +-----------+-----+-----+
		 spiral                     dwindle

Usage
-----
1. Download the patch and apply according to the [general instructions](.).
2. Include the `fibonacci.c` source file and add `spiral` and/or `dwindle` to
   the `Layout` section of your `config.h` file. Example from
  `config.default.h`:

   	#include "fibonacci.c"
   	static Layout layout[] = {
   		/* symbol               function */
   		{ "[]=",                tile }, /* first entry is default */
   		{ "><>",                floating },
   		{ "(@)",                spiral },
   		{ "[\\]",               dwindle },
   	};
3. Default key bindings are [Ctrl]+[r] for `spiral` and [Ctrl]+[Shift]+r for
   `dwindle`.

Download
--------
* [dwm-fibonacci-5.8.2.diff](dwm-fibonacci-5.8.2.diff)
* [dwm-fibonacci-6.2.diff](dwm-fibonacci-6.2.diff)
* [dwm-fibonacci-20200418-c82db69.diff](dwm-fibonacci-20200418-c82db69.diff)

Author
------
* Jeroen Schot - <schot@a-eskwadraat.nl>

Maintainer
----------
* Niki Yoshiuchi - <nyoshiuchi@gmail.com>

Joe Thornber's spiral tiling for [Xmonad](http://www.xmonad.org) formed the
inspiration for this patch. Thanks to Jan Christoph Ebersbach for updating this
patch for versions 4.5 to 4.9.
