stickyindicator
===============

Description
-----------
This is a patch for [sticky](../sticky) users who want an indicator in their bar to show when a window is sticky. The icon will appear underneath the floating icon. The shape is filled in when you are on the sticky window's original tag(s), and appears as an outline otherwise.

The indicator icon is drawn using an X11 wrapper to handle drawing scaled polygons. Because of this, the icon is very versitile. It can be changed by editing the vertices stored in the config variable `stickyicon[]`.

The defaut icon represents a bookmark, akin to this lovely representation made using box drawing characters:
	┌──┐
	│┈┈│
	│╱╲│

Download
--------
* [dwm-stickyindicator-6.2.diff](dwm-stickyindicator-6.2.diff)
* [dwm-stickyindicator-fancybarfix-6.2.diff](dwm-stickyindicator-fancybarfix-6.2.diff) (version compatable with fancybar)

Tip: make sure to install this on top of [sticky](../sticky).

Author
------
* Timmy Keller <applesrcol8796@gmail.com>
