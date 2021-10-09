launcher
========

Description
-----------
The bar at the top will have buttons that you can click to launch programs and commands.

Usage:
------
In config.h make a command:


	/* launcher command (Must be NULL terminated) */
	static const char* surf[]      = { "surf", "duckduckgo.com", NULL };


Then add it to the launchers array:


	static const Launcher launchers[] = {
	       /* command       name to display */
	        { surf,         "surf" },
	};


The result will be a little button that says "surf" at the top bar. When you click it, it launches surf. Have fun :D

Download
--------
* [dwm-launchers-20200527-f09418b.diff](dwm-launchers-20200527-f09418b.diff)

Author
------
* [Adham Zahran](mailto:adhamzahranfms@gmail.com)

