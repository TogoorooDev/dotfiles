blinking cursor
===============

Description
-----------
This patch allows the use of a blinking cursor.

To demonstrate the available cursor styles, try these commands:
	echo -e -n "\x1b[\x30 q" # Blinking block
	echo -e -n "\x1b[\x31 q" # Blinking block (default)
	echo -e -n "\x1b[\x32 q" # Steady block
	echo -e -n "\x1b[\x33 q" # Blinking underline
	echo -e -n "\x1b[\x34 q" # Steady underline
	echo -e -n "\x1b[\x35 q" # Blinking bar
	echo -e -n "\x1b[\x36 q" # Steady bar
	echo -e -n "\x1b[\x37 q" # Blinking st cursor
	echo -e -n "\x1b[\x38 q" # Steady st cursor

When drawing is triggered, the cursor does not blink.

Notes
-----
* Only cursor styles 0, 1, 3, 5, and 7 blink.  Set `cursorstyle` accordingly.
* Cursor styles are defined [here](https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h4-Functions-using-CSI-_-ordered-by-the-final-character-lparen-s-rparen:CSI-Ps-SP-q.1D81).

Download
--------
* [st-blinking\_cursor-20200531-a2a7044.diff](st-blinking_cursor-20200531-a2a7044.diff)

Authors
-------
* Genki Sky - <https://lists.suckless.org/hackers/1708/15376.html>
* Steve Ward - <planet36@gmail.com>
* jvyden
