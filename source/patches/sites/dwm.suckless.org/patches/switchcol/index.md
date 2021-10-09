switchcol
=========

Description
-----------
Switch focus between the 2 columns (master or stack) easily. This patch only
has one function, it remembers the most recently focused client in the 2
columns for each tag (it is implemented by searching the stack list to find
the most recent client in the other column).

Configuration
-------------
	/*config.h*/
	{ MODKEY,                       XK_n,   switchcol,   {0} },

Download
--------
* [dwm-switchcol-6.1.diff](dwm-switchcol-6.1.diff) (1126b) (20160325)

Author
------
* phi <crispyfrog@163.com>
