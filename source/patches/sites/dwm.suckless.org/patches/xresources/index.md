Xresources
==========

Description
-----------
This patch allows to handle settings from Xresources. It differs from xrdb patch in that it can handle any kind of setting as opposed to only color settings.

The -20210314 patch adds an example on how you could set a custom font.

Settings in config.h
--------------------
In `resources` struct is written the name, the type, and the address of the setting.

	 Name                    Type                 Address
	--------------------------------------------------------
	 "nmaster"               INTEGER              &nmaster
	 "mfact"                 FLOAT                &mfact
	 "color1"                STRING               &color1

In Xresources file setting names shoud be prefixed with "dwm."

	dwm.nmaster:
	dwm.mfact:
	dwm.color1:

This patch is a port of the st patch of the same name, it also borrows some code from dwm's xrdb patch, so a thank is in order for the authors of those patches.

Download
--------
* [dwm-xresources-6.2.diff](dwm-xresources-6.2.diff) (11/06/2020)
* [dwm-xresources-20210314.diff](dwm-xresources-20210314.diff) (14/03/2021)
* [dwm-xresources-20210827-138b405.diff](dwm-xresources-20210827-138b405.diff)


Author
------
* MLquest8 (miskuzius at gmail.com)
