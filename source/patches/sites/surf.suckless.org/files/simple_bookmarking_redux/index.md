Simple bookmarking, redux
=========================

Description
-----------
Modify your config.h just before the definition of `keys[]`:

	#define BM_PICK { .v = (char *[]){ "/bin/sh", "-c", \
	"xprop -id $0 -f _SURF_GO 8s -set _SURF_GO \
	`cat ~/.surf/bookmarks | dmenu || exit 0`", \
	winid, NULL } }

	#define BM_ADD { .v = (char *[]){ "/bin/sh", "-c", \
	"(echo `xprop -id $0 _SURF_URI | cut -d '\"' -f 2` && \
	cat ~/.surf/bookmarks) | sort -u > ~/.surf/bookmarks_new && \
	mv ~/.surf/bookmarks_new ~/.surf/bookmarks", \
	winid, NULL } }

Then, inside `keys[]`, add:

	{ MODKEY,               GDK_b,      spawn,      BM_PICK },
	{ MODKEY|GDK_SHIFT_MASK,GDK_b,      spawn,      BM_ADD },

### Modkeys

**CTRL-b**

Executes dmenu(1) displaying the list of bookmarks.

**CTRL-SHIFT-b**

Adds the current page to the list of bookmarks, while removing duplicate entries.

Author
------
* Lorenzo Bolla `<lbolla at gmail dot com>`
