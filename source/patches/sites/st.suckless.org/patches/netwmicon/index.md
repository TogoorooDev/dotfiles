netwmicon
=========

Description
-----------
Enables to set *\_NET\_WM\_ICON* which hardcodes an icon for st. An icon is
already defined in the file *icon.h* which was created by the theme
[flat-remix](https://github.com/daniruiz/flat-remix).

Generally the icon of an application is defined by its desktop-entry. A patch
with the name [desktopentry](../desktopentry) already exists for this purpose.
However, some programs like tint2 do not respect the desktopentry and rely
instead on an hardcoded icon which has to be defined by *\_NET\_WM\_ICON*.
Since st does not define *\_NET\_WM\_ICON* those programs will display some
default icon (which is ugly).

Defining your own icon
----------------------
You can of course change the icon to any icon you want. Just grab some icon
from your favorite icon-theme. The tricky part is that it needs to be encoded
as *"an array of 32bit packed CARDINAL ARGB with high byte being A, low byte
being B" -
[Source](https://specifications.freedesktop.org/wm-spec/1.3/ar01s05.html)*.
This can be done with the script [netwmicon.sh](netwmicon.sh). It takes as
argument the icon-file and prints to stdout the encoded icon. Redirect it to
icon.h to save it and reinstall st. You need to install both *imagemagick* and
*inkscape* for the script to work.

Download
--------
* [st-netwmicon-0.8.4.diff](st-netwmicon-0.8.4.diff)
* [netwmicon.sh](netwmicon.sh)

Authors
-------
* Aleksandrs Stier
