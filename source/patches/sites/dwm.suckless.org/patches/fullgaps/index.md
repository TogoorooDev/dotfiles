fullgaps
========

Description
-----------
This patch adds gaps between client windows. It is similar to [gaps](../gaps/),
but contains additional functionality:
* it also adds outer gaps (between the clients and the screen frame), as well
  as a gap between the master and stack area,
* it adds keybindings to change the gap size at runtime: [Alt]+[-]/[Alt]+[=] to
  decrease/increase the gap size and [Alt]+[Shift]+[=] to set it to zero.

The configuration variable `gappx` contains the default gap size.

Download
--------
* [dwm-fullgaps-6.2.diff](dwm-fullgaps-6.2.diff)
* [dwm-fullgaps-20200508-7b77734.diff](dwm-fullgaps-20200508-7b77734.diff)

The following patch allows for gaps to be toggled, and also uses a `Gap` struct
to contain the gap information, in anticipation of this being used with
[pertag](../pertag/). (To use this, apply the patch *instead* of the default
fullgaps patch.)

[Alt]+[Shift]+[=] to toggle. [Alt]+[Shift]+[-] to reset to `config.h` defaults.

* [dwm-fullgaps-toggle-20200830.diff](dwm-fullgaps-toggle-20200830.diff)

Author
------
* Maciej Janicki <mail@macjanicki.eu>
* David Julien <swy7ch@protonmail.com> (20200504-b2e1dfc port)
* Klein Bottle <kleinbottle4@gmail.com> (dwm-fullgaps-toggle...)
