Incremental output
==================
This patch causes dmenu to print out the current text each time a key is pressed.

This is useful as an incremental search feature, for example in surf's config.h:

	#define INCSEARCH { .v = (char *[]) { "/bin/sh", "-c", "dmenu -r < /dev/null | while read -r find; do xprop -id $0 -f _SURF_FIND 8s " "-set _SURF_FIND \"$find\"; done", winid, NULL } }


Download
--------
* [dmenu-incremental-20160702-3c91eed.diff](dmenu-incremental-20160702-3c91eed.diff)
