dwmfifo
=======

Description
-----------
This patch adds support for using a command/control FIFO for dwm. I've added
commands that map 1-1 with the existing keybind actions. You can use this patch
to script dwm. As an example the following sequence of commands starts 2
terminals on each of the 2 monitors.

	echo term > /tmp/dwm.fifo
	sleep 0.5
	echo term > /tmp/dwm.fifo
	sleep 0.5
	echo focusmon+ > /tmp/dwm.fifo
	sleep 0.5
	echo term > /tmp/dwm.fifo
	sleep 0.5
	echo term > /tmp/dwm.fifo

The sleep in between is currently needed to avoid buffering up more than a
single command. You may experiment with the actual sleep value.

Similarly you can modify your config.h and add more commands that you may want
to execute (like tabbed-surf or similar).

Download
--------
* [dwm-dwmfifo-6.1.diff](dwm-dwmfifo-6.1.diff) (6.9k) (2014-01-29)

Author
------
* sin - <sin@2f30.org>
