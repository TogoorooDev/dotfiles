mark
====

Description
-----------
This patch provides an mechanism to easily jump between any 2 clients, or to
swap any 2 clients through shortcuts by introcuding mark. The mark is global,
and only one mark is allowed at the same time. The marked client is
distinguished from other clients by having a different border color.

This patch adds 3 functions to dwm:

* togglemark - mark/unmark current focused client.
* swapclient - swap focused client with marked client
* swapfocus - swap focus with mark.

Configuration
-------------
	static const char normmarkcolor[]   = "#775500";	/*border color for marked client*/
	static const char selmarkcolor[]    = "#775577";	/*border color for marked client on focus*/

	/*basic key mappings*/
	{ MODKEY,                       XK_semicolon,togglemark,   {0} },
	{ MODKEY,                       XK_o,      swapfocus,      {0} },
	{ MODKEY,                       XK_u,      swapclient,     {0} },

Some ideas for combinations of key mappings:

* togglemark x2  clear the mark
* swapclient, swapfocus shift the client to another client frame without losing
  focus
* swapclient, togglemark x2  swap 2 clients and clear the mark
* swapfocus, togglemark x2  jump to mark and clear the mark

Download
--------
This patch has now been updated to 6.2.  
The recommended version is dwm-6.2-mark-new.diff. (updated on 2020-10-05)

* [dwm-mark-new-6.2.diff](dwm-mark-new-6.2.diff)  
* [dwm-mark-new-6.1.diff](dwm-mark-new-6.1.diff)  
* [dwm-mark-6.1.diff](dwm-mark-6.1.diff)  

Author
------
* phi <crispyfrog@163.com>
* mrkajetanp <kajetan.puchalski@tuta.io> (6.2 update)
