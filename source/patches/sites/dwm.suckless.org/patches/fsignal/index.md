fsignal
=======

Description
-----------
Send "fake signals" to dwm for handling, using xsetroot. This will not conflict
with the status bar, which also is managed using xsetroot.

Usage areas can for example be setting layout through dmenu, or other external
applications.

Usage
-----
A signal can be sent for example in this way `xsetroot -name "fsignal:1"` to
send the signal '1'.

Signal handlers are defined in config.h as:

	static Signal signals[] = {
		/* signum               function        argument*/
		{ 1,                    setlayout,      {.v = 0} },
		...
	};

This can then be triggered through dmenu with this script:

	#!/bin/bash
	layouts="echo -e tiled\ncolumns\n..."
	layout=$($layouts | dmenu "$@")
	
	if [[ "$layout" == "tiled" ]];then xsetroot -name "fsignal:1"; fi
	...

...or however you want to use it :)

Download
--------
* [dwm-fsignal-6.2.diff](dwm-fsignal-6.2.diff)

Authors
-------
* Chris Noxz - <chris@noxz.tech>
* Nihal Jere <nihal@nihaljere.xyz>
