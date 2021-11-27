open\_copied\_url
=================

Description
-----------
Open contents of the clipboard in a user-defined browser.

The clipboard in this case refers to the CLIPBOARD selection which gets
populated when pressing e.g. C-c.

Instructions
------------
Add a keybinding like the following example to "shortcuts" in config.h:

	{ MODKEY, XK_v, opencopied, {.v = "firefox"} },

Set the .v field of the last parameter to the program you want to bind to the key.

Notes
-----
By default this patch binds the Mod+o to "xdg-open". This allows users
to open the contents of the clipboard in the default browser.

Download
--------
* [st-openclipboard-20190202-0.8.1.diff](st-openclipboard-20190202-0.8.1.diff)
* [st-openclipboard-20190202-3be4cf1.diff](st-openclipboard-20190202-3be4cf1.diff)
* [st-openclipboard-20210802-2ec571.diff](st-openclipboard-20210802-2ec571.diff)

Authors
-------
* Michael Buch - <michaelbuch12@gmail.com>
* Sai Praneeth Reddy - <spr.mora04@gmail.com> (0.8.1, open external programs
  independently)
