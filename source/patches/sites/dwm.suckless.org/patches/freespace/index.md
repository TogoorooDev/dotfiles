freespace
=========

Description
-----------
New variable panel[4] saves space at the borders of the screen for the external
panel.

	+----------------+-+
	| |   panel[0]   | |
	+-+--------------+-+
	| |              | |
	|2|              |3|
	| |              | |
	+-+--------------+-+
	| |   panel[1]   | |
	+----------------+-+

In tiled and monocle layouts this space becomes borders of the windows; in
floating layout windows attach to these borders

Issue
-----
When there is only one master window in tiled layout with panel[2] set not to
zero its right border gets out of the screen

Download
--------
* [dwm-freespace-20180109-db22360.diff](dwm-freespace-20180109-db22360.diff)

Author
------
* Platon Ryzhikov - <ihummer63@yandex.ru>
