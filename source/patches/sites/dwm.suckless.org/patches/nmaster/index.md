nmaster
=======

History
-------
This patch restores the ability to have multiple clients in the master area of
the tiled layout. This feature was dropped from vanilla dwm in version 4.4. The
ntile mode from below is included in dwm as of version 6.0.

Description
-----------
The figures show how tiling will work when the patch is applied.

	ntile         (-|=)
	+----------+------+
	|          |      |
	|          +------+
	|----------|      |
	|          +------+
	|          |      |
	+----------+------+

	nbstack       (-|-)
	+--------+--------+
	|        |        |
	|        |        |
	|-----+--+--+-----+
	|     |     |     |
	|     |     |     |
	+-----+-----+-----+

Usage
-----
* Download `nmaster.c` into the source directory of dwm.
* Add `nmaster` default value to your `config.h`.
* Include `nmaster.c` in `config.h` after the definition of `nmaster`.
* Add `ntile` and/or `nbstack` to your layouts.
* Add keybindings to `incnmaster` and/or `setnmaster` to your `config.h`.

Example
-------
	static const int nmaster = 2;  /* default number of clients in the master area */

	#include "nmaster.c"

	static const Layout layouts[] = {
		/* symbol     arrange function */
		{ "-|=",      ntile },
		{ "-|-",      nbstack },
	...

	static Key keys[] = {
		/* modifier                     key        function        argument */
		{ MODKEY,                       XK_a,      incnmaster,     {.i = +1 } },
		{ MODKEY,                       XK_z,      incnmaster,     {.i = -1 } },
		{ MODKEY,                       XK_x,      setnmaster,     {.i = 2 } },
		{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0] } },
		{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[1] } },
	...

Download
--------
* [nmaster-ncol.c](nmaster-ncol.c) (dwm 5.9) (20101210) - additional ncol layout (multiple masters side by side)
* [nmaster-sym.c](nmaster-sym.c) (dwm 5.7.1) (20090927) - layout symbol shows the number of masters: `n]=`, `TnT`
* [nmaster.c](nmaster.c) (dwm 5.6.1) (20090908)
* see older versions in [historical patches](../historical/)
