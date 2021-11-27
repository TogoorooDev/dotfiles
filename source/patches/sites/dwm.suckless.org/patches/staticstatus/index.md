staticstatus
============

Description
-----------
This patch forces your status bar to stay put on a single monitor in a multi-monitor setup, no matter where your focus is. You can set which monitor you want the status bar to stay in with the statmonval value (in config.h), whose values are from 0 to (the number of monitors you have)-1. Monitors are enumerated in the order that they're picked up by dwm. Make sure to define the value in your config.h before compiling.

Configuration
-------------

	static const int statmonval = 0;

Download
--------
* [dwm-staticstatus-6.2.diff](dwm-staticstatus-6.2.diff)

Author
------
* Ian Ressa <ian@eonndev.com>
