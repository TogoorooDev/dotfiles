Bottom stack
============

Description
-----------
`bstack` and `bstackhoriz` are two bottom stack layouts for dwm.

Include the sources in your `config.h` (after the definition of `mfact`)
and update the layouts and key bindings.

	#include "bstack.c"
	#include "bstackhoriz.c"
	
	static const Layout layouts[] = {
		/* symbol     arrange function */
		...
		{ "TTT",      bstack },
		{ "===",      bstackhoriz },


Bottom Stack Tiling
-------------------
	bstack        (TTT)
	+-----------------+
	|                 |
	|                 |
	|                 |
	+-----+-----+-----+
	|     |     |     |
	|     |     |     |
	+-----+-----+-----+

	bstackhoriz   (===)
	+-----------------+
	|                 |
	|                 |
	|                 |
	+-----------------+
	+-----------------+
	+-----------------+
	+-----------------+

Download
--------
* [bstack.c](bstack.c) (dwm 5.6.1) (20090908)
* [bstackhoriz.c](bstackhoriz.c) (dwm 5.6.1) (20090908)
