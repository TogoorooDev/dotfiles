keyboard\_select
================

Description
-----------
This patch allows you to select and copy text to primary buffer with keyboard
shortcuts like the perl extension keyboard-select for urxvt.

Instructions
------------
The patch changes the config.def.h. Delete your config.h or add the shortcut
below if you use a custom one.

	Shortcut shortcuts[] = {
		...
		{ TERMMOD, XK_Escape, keyboard_select, { 0 } },
	};

Notes
-----
When you run "keyboard\_select", you have 3 modes available :

* move mode :   to set the start of the selection;
* select mode : to activate and set the end of the selection;
* input mode :  to enter the search criteria.

Shortcuts for move and select modes :

	 h, j, k, l:    move cursor left/down/up/right (also with arrow keys)
	 !, _, *:       move cursor to the middle of the line/column/screen
	 Backspace, $:  move cursor to the beginning/end of the line
	 PgUp, PgDown : move cursor to the beginning/end of the column
	 Home, End:     move cursor to the top/bottom left corner of the screen
	 /, ?:          activate input mode and search up/down
	 n, N:          repeat last search, up/down
	 s:             toggle move/selection mode
	 t:             toggle regular/rectangular selection type
	 Return:        quit keyboard_select, keeping the highlight of the selection
	 Escape:        quit keyboard_select

With h,j,k,l (also with arrow keys), you can use a quantifier. Enter a number
before hitting the appropriate key.

Shortcuts for input mode :

	 Return:       Return to the previous mode

Download
--------
* [st-keyboard\_select-20190207-3be4cf1.diff](st-keyboard_select-20190207-3be4cf1.diff)
* [st-keyboard\_select-0.8.1.diff](st-keyboard_select-0.8.1.diff)
* [st-keyboard\_select-0.8.2.diff](st-keyboard_select-0.8.2.diff)
* [st-keyboard\_select-20200617-9ba7ecf.diff](st-keyboard_select-20200617-9ba7ecf.diff)

Authors
-------
* Tonton Couillon - <la dot luge at free dot fr>
