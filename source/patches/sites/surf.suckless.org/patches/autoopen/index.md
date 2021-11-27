auto open downloads
===================

Description
-----------

This patch uses xdg-open to open a download once it has finished.

It simply replaces this:

	"xterm -e \"wget --load-cookies ~/.surf/cookies.txt '$0';\"", \

with this:

	"ofile=\"$(xdg-user-dir DOWNLOAD)/$(basename \"$0\")\"; wget --load-cookies ~/.surf/cookies.txt -O \"$ofile\" \"$0\"; xdg-open \"$ofile\"", \

in your config.def.h file.


Download
--------

* [surf-0.3-autoopen.diff](surf-0.3-autoopen.diff) (.5k) (20100705)

Author
------

* Matthew Bauer <mjbauer95@gmail.com>
