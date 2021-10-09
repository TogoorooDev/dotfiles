next prev tag
=============

Description
-----------
* Increment or decrement the selected tag
* [shiftview](//lists.suckless.org/dev/1104/7590.html).c is a better
  implementation of this, allowing you to rotate the selected tags

Download
--------
* [nextprevtag.c](nextprevtag.c)

Example
-------
	static Key keys[] = {
		/* ... */
		{ MODKEY,              XK_i,           view_adjacent,  { .i = +1 } },
		{ MODKEY,              XK_u,           view_adjacent,  { .i = -1 } },
		/* ... */
	};

	static Button buttons[] = {
		/* ... */
		{ ClkTagBar,            0,              Button4,        view_adjacent,     { .i = -1 } },
		{ ClkTagBar,            0,              Button5,        view_adjacent,     { .i = +1 } },
		/* ... */
	};


Author
------
* Rob Pilling - robpilling gmail com
