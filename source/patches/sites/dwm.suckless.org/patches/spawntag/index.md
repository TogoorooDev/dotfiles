spawntag
========

Description
-----------
Spawn application whenever a tag is middle clicked. This patch also include
`GTKCMD`, helper for launching gtk application.

Example usage:

	static const Arg tagexec[] = {
		{ .v = termcmd },
		GTKCMD("org.gnome.Nautilus"),
		GTKCMD("visual-studio-code"),
		SHCMD("lxterminal -t AlsaMixer -e /usr/bin/alsamixer"),
		GTKCMD("discord"),
		SHCMD("lxterminal -t Cmus  -e /usr/bin/cmus"),
		{ .v = termcmd },
		GTKCMD("personal-firefox"),
		GTKCMD("firefox")
	};

Download
--------
* [dwm-spawntag-6.2.diff](dwm-spawntag-6.2.diff) (2021-05-19)

Author
-------
* Piyush Pangtey <gokuvsvegita@gmail.com>
