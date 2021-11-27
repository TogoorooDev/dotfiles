externalpipe
============

Description
-----------

Pipe the current page's source to an external program. This is particularly
helpful for keyboard-based link following and also for viewing the source in an
external editor. Works both when javascript is enabled and disabled.

Example
-------
Install the below shell scripts into your `$PATH`:
* [surf_linkselect.sh](surf_linkselect.sh) - extracts links via xmllint and
  pipes to dmenu, converts selected link to valid URL.
* [edit_screen.sh](edit_screen.sh) - open source in `$EDITOR` for copying text.


Add to your `config.h`:
	static char *linkselect_curwin [] = { "/bin/sh", "-c",
		"surf_linkselect.sh $0 'Link' | xargs -r xprop -id $0 -f _SURF_GO 8s -set _SURF_GO",
		winid, NULL
	};
	static char *linkselect_newwin [] = { "/bin/sh", "-c",
		"surf_linkselect.sh $0 'Link (new window)' | xargs -r surf",
		winid, NULL
	};
	static char *editscreen[] = { "/bin/sh", "-c", "edit_screen.sh", NULL };
	...
	static Key keys[] = {
		{ MODKEY,                GDK_KEY_d, externalpipe, { .v = linkselect_curwin } },
		{ GDK_SHIFT_MASK|MODKEY, GDK_KEY_d, externalpipe, { .v = linkselect_newwin } },
		{ MODKEY,                GDK_KEY_o, externalpipe, { .v = editscreen        } },
		...
	}

Now you have the new keybindings:
- **Ctrl-d** - open dmenu with links, select to follow in current surf window
- **Ctrl-Shift-d** - open dmenu with links, select to open in new surf window
- **Ctrl-o** - view sourcecode for the current page in your editor


Download
--------

* [surf-2.0-externalpipe.diff](surf-2.0-externalpipe.diff) (2379) (20190807)

Author
------

* Miles Alan - m@milesalan.com
* Rob Pilling - robpilling@gmail.com (author of st externalpipe, which pipe code is based on)