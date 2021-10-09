Cool autostart
==============

Description
-----------
Allow dwm to execute commands from `autostart` array in your config.h file.
And when you exit dwm all processes from `autostart` array will be killed.

Example
-------

	static const char *const autostart[] = {
		"mpd-notification", NULL,
		"hsetroot", "-center", "/usr/home/bit6tream/pic/wallapper.png", NULL,
		"xrdb", "/usr/home/bit6tream/.config/X/Xresources", NULL,
		"sh", "-c", "while :; do dwmstatus.sh -; sleep 60; done", NULL,
		"dunst", NULL,
		"picom", NULL,
		NULL
	};

Attention
---------
Commands from array are executed using execvp().
So if you need to execute shell command you need to prefix it with
`"sh", "-c"` (change `sh` to any shell you like).

Download
--------
* [dwm-cool-autostart-6.2.diff](dwm-cool-autostart-6.2.diff)

Authors
-------
* bit6tream <bit6tream@cock.li> [bit6tream's gitlab](https://gitlab.com/bit9tream)
* zsugabubus <zsugabubus@national.shitposting.agency>
