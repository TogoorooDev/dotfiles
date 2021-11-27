setborderpx
===========

Description
-----------

This patch allows you to change border pixels at runtime.

Default key bindings
--------------------
	 Key                    Argument   Description
	----------------------------------------------------
	 Mod-Shift-plus         +1         Increase borderpx
	 Mod-Shift-minus        -1         Decrease borderpx
	 Mod-Shift-numbersign    0         Reset borderpx

Notes
-----
You might want to set resizehints in config.h to zero to get smooth animations
when increasing or decreasing border pixels.

Download
--------
* [dwm-setborderpx-6.2.diff](dwm-setborderpx-6.2.diff) - 2020-05-15

Author
------
* Aaron Duxler <aaron@duxler.xyz>
