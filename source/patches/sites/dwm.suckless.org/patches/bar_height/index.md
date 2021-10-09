bar height
==========

This patch allows user to change dwm's default bar height.

Usage
-----

Change `user_bh` variable in you're config.h If `user_bh` is equal to 0 dwm will calculate bar height like it did before.

	static const int user_bh = 0; /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

Download
--------
* [dwm-bar-height-6.2.diff](dwm-bar-height-6.2.diff)

Authors
-------
* bit6tream <bit6tream@cock.li> ([bit6tream's gitlab](https://gitlab.com/bit9tream))
