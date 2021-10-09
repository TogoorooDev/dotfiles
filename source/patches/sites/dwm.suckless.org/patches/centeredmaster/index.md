centeredmaster
==============

Description
-----------
`centeredmaster` and `centeredfloatingmaster` are two stack layouts for dwm.

`centeredmaster` centers the nmaster area on screen, using `mfact * monitor
width & height`, with the stacked windows distributed to the left and right. It
can be selected with [Alt]+[u].

With one and two clients in master respectively this results in:

	+------------------------------+       +------------------------------+
	|+--------++--------++--------+|       |+--------++--------++--------+|
	||        ||        ||        ||       ||        ||        ||        ||
	||        ||        ||        ||       ||        ||   M1   ||        ||
	||        ||        ||        ||       ||        ||        ||        ||
	||  S2    ||   M    ||   S1   ||       ||        |+--------+|        ||
	||        ||        ||        ||       ||        |+--------+|        ||
	||        ||        ||        ||       ||        ||        ||        ||
	||        ||        ||        ||       ||        ||   M2   ||        ||
	||        ||        ||        ||       ||        ||        ||        ||
	|+--------++--------++--------+|       |+--------++--------++--------+|
	+------------------------------+       +------------------------------+

`centeredfloatingmaster` centers the nmaster area on screen, using `mfact *
monitor width & height` over a horizontally tiled `stack` area, comparable to a
scratchpad. It can be selected with [Alt]+[o].

With one and two clients in master respectively this results in:

	+------------------------------+       +------------------------------+
	|+--------++--------++--------+|       |+--------++--------++--------+|
	||        ||        ||        ||       ||        ||        ||        ||
	||    +------------------+    ||       ||    +--------++--------+    ||
	||    |                  |    ||       ||    |        ||        |    ||
	||    |                  |    ||       ||    |        ||        |    ||
	||    |        M         |    ||       ||    |   M1   ||   M2   |    ||
	||    |                  |    ||       ||    |        ||        |    ||
	||    +------------------+    ||       ||    +--------++--------+    ||
	||        ||        ||        ||       ||        ||        ||        ||
	|+--------++--------++--------+|       |+--------++--------++--------+|
	+------------------------------+       +------------------------------+

These stack layouts can be useful on large screens, where `monocle` or `htile`
might be either too large or forcing the user to type in a corner of the
screen. They allow for instance to center the editor while being able to keep
an eye on background processes (logs, tests,...)

Download
--------
* [dwm-centeredmaster-6.1.diff](dwm-centeredmaster-6.1.diff)
* [dwm-centeredmaster-20160719-56a31dc.diff](dwm-centeredmaster-20160719-56a31dc.diff)

Authors
-------
* [Jérôme Andrieux](http://blog.jardinmagique.info) - <jerome@gcu.info>
* Laslo Hunhold - <dev@frign.de> (6.1, git ports)
