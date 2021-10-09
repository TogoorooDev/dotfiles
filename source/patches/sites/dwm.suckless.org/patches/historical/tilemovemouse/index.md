Move tiled window with mouse
============================

Description
-----------
tilemovemouse() lets you drag a client to a different position *without*
floating it. Reordering windows this way is fun.

	static Button buttons[] = {
		/* click          event mask      button      function        argument */
		{ ClkClientWin,   MODKEY,         Button1,    tilemovemouse,  {0} },
	};

Download
--------
* [tilemovemouse](//lists.suckless.org/dwm/0903/7773.html)
