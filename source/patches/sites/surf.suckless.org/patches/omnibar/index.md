Omnibar
=======
Run a command each time an URI is loaded. Since the URI may be passed as
argument, this patch along with a proper script allows to manage browsing
history in many convenient ways.

The omnibar script store all URIs, including ones visited by clicking on links,
and use them to auto-complete when you type on dmenu. The items are sorted by
number of views.

For [tabbed](//tools.suckless.org/tabbed/) users, you may also want to add
the following to your tabbed config.h:

	#define GOTO { \
		.v = (char *[]){"/bin/sh", "-c", \
			"~/.surf/omnibar goto $0 $1", winid, "_TABBED_SELECT_TAB", NULL \
		} \
	}

Now you can use the following key (don't forget to remove the old one):

	{ MODKEY,                       XK_t,      spawn,          GOTO },


Download
--------
* [surf-0.7-omnibar.diff](surf-0.7-omnibar.diff)
* [omnibar](https://raw.githubusercontent.com/clamiax/.surf/374e101748093215e8ecbf00a24a764932b60ed7/omnibar)

Author
------
* Claudio Alessi <smoppy@gmail.com>
