How does a tag-mask work?
=========================
There exists extensive documentation in this wiki about tags in dwm.

This article will concentrate on how to manage bit masks in default rules.

In order to manage a number of tags efficiently, dwm uses bitmasks.

Looking at dwm's code, the tags array is defined in the familiar way:

	static const char tags[][MAXTAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

We have 9 tags, labelled numerically (but the labels are just that, labels;
they don't have any intrinsic values).

Within dwm's code, each client's tag list is managed as a bit mask: given an
integer binary representation, tags are associated from the least significant
bit (rightmost) to the most significant bit (leftmost).

For example, tag '1' is 000000001, while tag 9 is 100000000. Tag '3' is
000000100 (third from the right)

The code in dwm.c that uses the rules array matches the current client
properties with each rule, and when matched, it bit-ands the tags member of the
rules array element with TAGMASK, then bit-ors it with the client's current tag
mask.

	/* rule matching */
	XGetClassHint(dpy, c->win, &ch);
	for(i = 0; i < LENGTH(rules); i++) {
		r = &rules[i];
		if((!r->title || strstr(c->name, r->title))
				&& (!r->class || (ch.res_class && strstr(ch.res_class, r->class)))
				&& (!r->instance || (ch.res_name && strstr(ch.res_name, r->instance)))) {
			c->isfloating = r->isfloating;
			c->tags |= r->tags & TAGMASK;
		}
	}

The client's tags value is therefore built sequentially through the rules. If
the tagmask in rules is 0, the currently selected tag becomes the client's tags
value.

	if(!c->tags)
		c->tags = tagset[seltags];

TAGMASK is the all-one bit mask, setting to 1 all the bits corresponding to a
tag in the tags array. TAGMASK is defined in dwm.c as:

	#define TAGMASK ((int)((1LL << LENGTH(tags)) - 1))

and would produce, for the standard tags array, the bit configuration 111111111
(nine 1's).

The reason for using TAGMASK is that it disallows the rules array to select a
tag for which we do not have a representation in the tags array.

Now, this method of representing tags allows us to express our preferences
regarding tags using bit-wise operators.

When are tagmasks used?
-----------------------
Please note that dwm always uses tagmasks: even when one tag is selected as the
visible tag, it is actually internally managed as a tagmask.

To prove this, use the command combination that allows you to bring more than
one tag into view (usually Mod1-Ctrl-tagnumber). If you select tags 1, 2 and 3,
and then open a new xterm using Mod1-Shift-Return, the new xterm will be tagged
with tags 1, 2 and 3.

A very powerful feature.

What does tagmask 0 mean?
-------------------------
It means that the current tagmask should be selected for this window: if more
than one tag are currently visible, all the currently visible tags are going to
be associated to that window.

What does tagmask 1 << 8 mean?
------------------------------------
1 shifted to the left by eight positions generates mask 100000000, selecting
tag '9' (ninth from the right) in the the tags array.

What does ~0 mean?
------------------
Complement of 0 is all 1's. This indicates all tags should be selected. The tag
mask in rules is then filtered using the TAGMASK macro to adapt the mask to
just the available tags.

What does (1 << 8) - 1 mean?
----------------------------------
1 << 8 selects tag '9' only (100000000). Subtracting 1 to that bitmask
transforms all the 0's to the right of that tagmask into 1's (011111111),
effectively selecting all tags except '9'.
