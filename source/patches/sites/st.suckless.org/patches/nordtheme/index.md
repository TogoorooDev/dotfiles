nordtheme
=========

Description
-----------
*"Inspired by the beauty of the arctic, the colors reflect the cold, yet harmonious world of ice and the colorfulness of the Aurora Borealis."* - [Nord Theme](https://www.nordtheme.com/)

There are also many [ports](https://www.nordtheme.com/ports) for other programs like [vim](https://www.nordtheme.com/ports/vim) and [tmux](https://www.nordtheme.com/ports/tmux) to make the overall appearance coherent. I would recommend to use it in combination with the arc-theme for gtk (fits perfectly).

Selection-Colors
----------------

The default behaviour of st is to reverse the fore- and background colors of each selected cell. If you want that the selection-colors are not reveresed but instead have fixed fore- and background colors apply on top of this patch the [selectioncolors](../selectioncolors/)-patch. Then set the following settings in your config.h:

	static unsigned int defaultcs = 257;
	static unsigned int defaultrcs = 257;
	unsigned int selectionbg = 0;
	unsigned int selectionfg = 257;
	static int ignoreselfg = 1;

Download
--------
* [st-nordtheme-0.8.2.diff](st-nordtheme-0.8.2.diff)

Authors
-------
* Aleksandrs Stier
