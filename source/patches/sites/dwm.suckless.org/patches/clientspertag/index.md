clients per tag
===============

Description
-----------
This patch modifies the tile() layout to limit the maximum number of visible
clients per tag. Out-of-limit windows are arranged behind the visible ones
in the slave area.

	+-----------------------+  +-----------------------+
	| -1/3                  |  |  2/3                  |
	+-----------+-----------+  +-----------+-----------+
	|           |           |  |           |           |
	|           |     2     |  |           |           |
	|           |           |  |           |           |
	|     1     +-----------+  |     1     |     2     |
	|           |           |  |           |           |
	|           |     3     |  |           |           |
	|           |           |  |           |           |
	+-----------+-----------+  +-----------+-----------+
	          cpt=-1                     cpt=2

Usage
-----
1. Download the patch and apply according to the [general instructions](.).
2. The patch adds two new keybindings (META-q/a) which set cpt to ^2 and ^3:

If the argument to 'clientspertag' starts with '^' pressing twice the key
will result on swapping between the defined value and -1.

* To show all windows put "-1" as argument value.
* To only display floating windows put "0" as argument.
* For a toggling pair put "^2".

	static Key keys[] = {
		/* modifier      key        function        argument */
		...
		{ MODKEY,        XK_q,      clientspertag,  {.v="^2"} },
		{ MODKEY,        XK_a,      clientspertag,  {.v="^3"} },
	};

Download
--------
* [dwm-clientspertag-5.6.1.diff](dwm-clientspertag-5.6.1.diff)

Maintainer
----------
* pancake - <pancake@nopcode.org>
