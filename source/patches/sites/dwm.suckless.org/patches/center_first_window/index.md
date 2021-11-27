center first window
===================

Description
-----------

This patch centers window if it is a single window opened.  When any other
window opens, then they tile normally, and if all other windows will close, it
will center again.

It is usefull for apps like - terminal, if you don't want that it cover all of
the master area, when no other apps are opened.

Usage
-----

It can be enabled for any window in config file, by setting `CenterThisWindow`
to `1`:

	/* class      	instance    title    tags mask     isfloating        CenterThisWindow?     monitor */
	{ "st",         NULL,       NULL,    0,            0,     	     1,		           -1 },

With one and two clients in master respectively results in:

       +-----------------------------+         +-----------------------------+
       |                             |         | +------------+ +----------+ |
       |                             |         | |            | |          | |
       |                             |         | |            | |          | |
       |       +-------------+       |         | |            | |          | |
       |       |    Single   |       |         | |  Terminal  | | Terminal | |
       |       |   Terminal  |       |         | |  Window 1  | | Window 2 | |
       |       |    Window   |       |         | |            | |          | |
       |       +-------------+       |         | |            | |          | |
       |                             |         | |            | |          | |
       |                             |         | |            | |          | |
       |                             |         | +------------+ +----------+ |
       +-----------------------------+         +-----------------------------+

Download
--------
* [dwm-centerfirstwindow-6.2.diff](dwm-centerfirstwindow-6.2.diff)

Authors
-------
* ზურა დავითაშვილი - <zdavitashvili0@gmail.com>
* Part of code is taken from reddit's post by `johannesthyssen`
