moveplace
=========

Description
-----------
This patch was culled from 'exresize' which in turn is based on 'maximize',
'moveresize', and 'savefloats'

This patch separates out the 'explace' (rename here 'moveplace') functionality
in case that is all you need, or if you want to use this with other patches.

Makes a window floating and 1/3rd the height and 1/3rd the width of the screen.

The window is then positioned in either the center, or one of 8 cardinal
directions depending on which key is pressed.

MOD+
	qwe
	asd
	zxc

with `s` being the center.

Download
--------
* [dwm-moveplace-20180524-c8e9479.diff](dwm-moveplace-20180524-c8e9479.diff) (2018-05-24)

Author
------
* cd
* Krister Svanlun - <krister.svanlund-AT-gmail.com> (original exresize)
