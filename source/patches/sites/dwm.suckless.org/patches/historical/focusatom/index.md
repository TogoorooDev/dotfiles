focus setting atom
==================

Description
-----------
With this patch, dwm monitors the content of the `_DWM_FOCUS` property in the 
root window (a 32-bit cardinal) and sets the focus accordingly, selecting the 
client tags and monitor if needed.

Usage
-----
After patching, you can use a modified version of lsw to print the window id:

	diff -up lsw-0.1/lsw.c lsw.new/lsw.c
	--- lsw-0.1/lsw.c	2006-10-13 11:09:18.000000000 +0200
	+++ lsw.new/lsw.c	2010-02-23 15:15:41.468637549 +0100
	@@ -63,7 +63,7 @@ main(int argc, char *argv[]) {
					continue;
				getname(wins[i]);
				if(buf[0])
	-				fprintf(stdout, "%s\n", buf);
	+				fprintf(stdout, "%s - %i\n", buf, wins[i]);
			}
		}
		if(wins)

And then call dmenu to choose a window by title, xprop to set it:

	win="$(lsw | grep -v ^\<unknown\> | dmenu | awk '{print $NF}')"
	test $win && xprop -root -f _DWM_FOCUS 32c -set _DWM_FOCUS $win

Notes
-----
* May not be extremely portable
* You can now use this with mainline lsw by using the -l parameter
* This patch is now historical since dwm supports \_NET\_ACTIVE\_WINDOW

Download
--------
* [dwm-r1507-focusatom.diff](dwm-r1507-focusatom.diff) (2057 bytes) (20100226)

Author
------
* Rafael Garcia - <rafael.garcia.gallego@gmail.com>
