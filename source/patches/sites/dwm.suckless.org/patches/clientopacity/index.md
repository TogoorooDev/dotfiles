clientopacity
=============

Description
-----------
This patch adds a default transparency parameter to config.h, which specifies the
transparency, all windows are started with. It also adds opacity to the ruleset, enabling to override the opacity on a per client basis.

Additionally it adds some shortcuts:

* MOD + Shift + Numpad_Add 	-> increase opacity of current focused window
* MOD + Shift + Numpad_Subtract -> decrease opacity of current focused window

It is based on the transparency patch of Christop Lohmann.

Download
--------
* [dwm-clientopacity-20201012-61bb8b2.diff](dwm-clientopacity-20201012-61bb8b2.diff)

Authors
-------
* Fabian Blatz - fabian.blatz at gmail period com
