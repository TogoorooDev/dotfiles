Three Column Layout
===================

Description
-----------
Three Column Layout is a new layout with a wide master panel centered on
the screen.

	+-----+-------------+-----+
	|     |             |     |
	|-----+             +-----+
	|     |      M      |     |
	|-----+             +-----+
	|     |             |     |
	+-----+-------------+-----+

Usage
-----
1. Include the `tcl.c` source file and add `tcl` to the `Layout` section of
   your `config.h` file. Example from `config.default.h`:

	#include "tcl.c"
	static Layout layout[] = {
		/* symbol               function */
		{ "[]=",                tile }, /* first entry is default */
		{ "><>",                floating },
		{ "|||",                tcl },
	};

Download
--------
* [tcl.c layout](tcl.c)

Maintainer
----------
* Chris Truett - <chris.truett@gmail.com>

Note
----
This layout idea was found in a rough form in this
[mailing list post](//lists.suckless.org/dev/1008/5506.html).
