instapaper
==========

Description
-----------

1. Add this to static Key keys[]:

	{ MODKEY,	GDK_i,	spawn,	{ .v = (char *[]){ "/bin/sh", "-c", "curl -s -d username=\"$(cat ~/.surf/instapaper | sed -n '1p')\" -d password=\"$(cat ~/.surf/instapaper | sed -n '2p')\" -d url=\"$(xprop -id $0 _SURF_URI | cut -d '\"' -f 2)\" https://www.instapaper.com/api/add > /dev/null", winid, NULL } } },

2. Save instapaper login:

Your instapaper login should go to ~/.surf/instapaper. Email first line; password second line.

For security you should run:

	chmod og-rwx

So only you can read and write to the file.


Now running you can press MODKEY+i (usually Ctrl+i) and your current page will be added to instapaper.

Author
------

* Matthew Bauer <mjbauer95@gmail.com>
