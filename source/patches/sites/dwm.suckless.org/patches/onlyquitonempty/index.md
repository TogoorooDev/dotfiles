onlyquitonempty
===============

Description
-----------
On the default keybinding of Mod-Shift-Q, it is possible to press it by
accident, closing all your work. This patch makes it so dwm will only exit if
no windows are open.

You probably have various other "windows" open according to the X server; this
includes not only a panel, but often also settings daemons, notification
daemons, odd scripts, or other X utilities. As a result, you will probably need
to consider changing `EMPTY_WINDOW_COUNT` to a number that works best for you.
You can get a list of open X windows with `xwininfo -tree -root`. The command
`xwininfo -tree -root | grep child | head -1` with an empty desktop should get
you most of the way there (although of course your terminal is open). Be
prepared to recompile a few times to test!

Version two adds an override shortcut as Ctrl-Mod-Shift-Q; this is obviously
configurable in config.h. It also removes a useless allocation, which could
even potentially be overflowed (`sizeof(Window) > 1`).

Download
--------
* [dwm-onlyquitonempty-20201204-61bb8b2.diff (version 2)](dwm-onlyquitonempty-20201204-61bb8b2.diff)
* [dwm-onlyquitonempty-20180428-6.2.diff (version 1)](dwm-onlyquitonempty-20180428-6.2.diff)

Author
------
* thatlittlegit - <personal@thatlittlegit.tk>
