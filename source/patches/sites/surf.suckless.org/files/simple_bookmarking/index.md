Simple bookmarking
==================

Description
-----------

change this script to fit your needs.

bookmarkurl:

	#!/bin/sh
	file=~/.surf/bookmarks
	url=`xprop -id $1 | grep URI | awk '{print $3}' | sed 's/\"//g'`
	title=`xprop -id $1 | grep WM_ICON_NAME\(STRING\) | cut -c 40- | sed 's/.$//g`
	echo $url $title | dmenu -p 'Add Bookmark' -b -w $1 >> $file

to add tags, when dmenu displays, simply tab, space and write your tag.
  

loadbookmark:

(needs a vertical patch on dmenu for convenience, choose the one you like,
Meillo's is the lightweight, Fresch's is the full featured)

	#!/bin/sh
	cat ~/.surf/bookmarks | dmenu -p 'Load Bookmark' -i -b -l 10 -w $1 | awk '{print $1}'

To make dmenu display bookmark with a tag only, add a grep part in the
first line and launch this script with the tag as argument.

bookmarkurl and loadbookmark can be launched with the following in config.h above the
"static Key keys[] = {" line:

	#define ADDBMK { \
		.v = (char *[]){ "/bin/sh", "-c", \
		     "bookmarkurl $0", winid, NULL \
		} \
	}

	#define LOADBMK(r, s, p) { \
		.v = (const char *[]){ "/bin/sh", "-c", \
		     "prop=\"$(loadbookmark $1)\" && xprop -id $1 -f $3 8s -set $3 \"$prop\"", \
		     "surf-setprop", winid, r, s, p, NULL \
		} \
	}
and

	{ MODKEY|GDK_SHIFT_MASK, GDK_KEY_z,      spawn,      ADDBMK },
	{ MODKEY,                GDK_KEY_z,      spawn,      LOADBMK("_SURF_URI", "_SURF_GO", PROMPT_GO) },

in the "static Key keys[] = {" part.

Author
------
- Julien Steinhauser <julien.steinhauser@orange.fr>
