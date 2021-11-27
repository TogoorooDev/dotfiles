Play External
=============

Description
-----------

This patch makes use of the following existing macro to pipe the current page uri to mpv when a hotkey is pressed.

	/* VIDEOPLAY(URI) */
	#define VIDEOPLAY(u) {\
		.v = (const char *[]){ "/bin/sh", "-c", \
		     "mpv --really-quiet \"$0\"", u, NULL \
		} \
	}

To customize the hotkey just change the following line in your config.h. (patch adds this in config.def.h).
	{ MODKEY,                GDK_KEY_w,      playexternal, { 0 } },


Download
--------

* [surf-playexternal-20190724-b814567.diff](surf-playexternal-20190724-b814567.diff) (1.6K) (20190724)

Author
------

* Daniel Nakhimovich <dnahimov@gmail.com>
