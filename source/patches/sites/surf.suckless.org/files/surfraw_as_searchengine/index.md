Surfraw as search engine
=========================

Description
-----------
Make sure to have surfraw installed.

Modify your config.h just before the definition of `keys[]`:

	#define SR_SEARCH { .v = (char *[]){ "/bin/sh", "-c", \
	"xprop -id $0 -f _SURF_GO 8s -set _SURF_GO \
	$(sr -p $(sr -elvi | tail -n +2 | cut -s -f1 | dmenu))", \
	winid, NULL } }

Then, inside `keys[]`, add:

	{ MODKEY,               GDK_s,      spawn,      SR_SEARCH },

### Modkeys

**CTRL-s**

Executes dmenu(1) displaying the list of elvis. Complete with TAB and enter
search terms. Confirm with ENTER.

Author
------
* Moritz Schönherr `<moritz dot schoenherr at gmail dot com>`
