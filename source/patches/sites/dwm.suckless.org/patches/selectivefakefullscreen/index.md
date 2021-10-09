selectivefakefullscreen
=======================

Description
-----------
Allows a specific application to fake a full screen while the rest behave as usual,
it's based on Jan Hendrik Farr's patch, [fakefullscreen](../fakefullscreen/).

Includes a modification to config.def.h in order to add a new member to Rules struct,
called "isfakefullscreen", set it to one for all the applications you want to
fake a full screen.

Download
--------
* [dwm-selectivefakefullscreen-20201130-97099e7.diff](dwm-selectivefakefullscreen-20201130-97099e7.diff)
* [dwm-selectivefakefullscreen-20200513-f09418b.diff](dwm-selectivefakefullscreen-20200513-f09418b.diff)

Changelog
---------
2020-11-30:
* Fix for resize issue

2020-05-13:
* Original patch

Author
------
* Francisco Javier Tapia - <link_1232@yahoo.com.mx>
