Setting rules in config.h
=========================

What does '`rules`' do?
-----------------------
The `rules` array allows treating of certain applications (clients) uniquely.
A rule has a matching and an action part. When a new client appears (sends a
maprequest), it is matched against the rules based on its class, instance
(`WM_CLASS`) and title (`WM_NAME`) properties and then the given tag and
floating mode setting actions are performed. The default tag mask is `0`, which
means the currently viewed tags and the default mode is tiled so isfloating is
`False` or `0`.

Example from the default config:

	static Rule rules[] = {
		/* class      instance    title       tags mask     isfloating   monitor */
		{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
		{ "Firefox",  NULL,       NULL,       1 << 8,       1,           -1 },
		{ "deadbeef", NULL,       NULL,       1 << 7,       0             0 }
	};

These rules make every Gimp and Firefox window floating and makes Firefox
windows appear on tag 9 instead of the currently viewed tags.
deadbeef similarly displays its window on tag 8 for a secondary display
monitor.

How does the matching work?
---------------------------
A client is matched if its properties contain the given strings as substrings
(case-sensitively) or `NULL` is given (which means anything is matched there).

More than one rule can be applied to a client, the rules are matched in order.

How to check these properties of a client?
------------------------------------------
The `xprop` utility can be used to get this information:
`WM_CLASS` is (instance, class) `WM_NAME` (or `_NET_WM_NAME`) is the title.

For example this shell script prints the relevant properties of the selected
client (if the properties does not contain '`=`' or '`,`'):

	xprop | awk '
		/^WM_CLASS/{sub(/.* =/, "instance:"); sub(/,/, "\nclass:"); print}
		/^WM_NAME/{sub(/.* =/, "title:"); print}'

How to add exception to a tagging rule?
---------------------------------------
It cannot be simply done. For example it is difficult to achieve that each
Firefox window goes to tag 9 except one specific dialog, which goes to tag 8,
because the tag masks of different matched rules are 'or'ed (and not overwritten).
