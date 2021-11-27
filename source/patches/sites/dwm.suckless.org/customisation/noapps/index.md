Remove application defaults from config.h
=========================================
The rules array is initialized, by default, to treat windows of class `Gimp`
and `Firefox` in a special way. If, like me, you don't want any application to
be treated in a special way, you must be careful when editing the rules array
initialization code.

The original code describes what each value represents within the Rule
structure.

	static Rule rules[] = {
		/* class      instance    title       tags mask     isfloating   monitor */
		{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
		{ "Firefox",  NULL,       NULL,       1 << 8,       True,        -1 },
	};

For instance, Gimp and Firefox will be labeled as floating windows, even if the
layout selected is Monocle or Tiled. In particular, the tag mask will attach
Firefox to tag '9'.

If we don't want any window class to be treated in a special way, we need to
initialize rules with at least one element:

	static Rule rules[] = {
		/* class      instance    title       tags mask     isfloating   monitor */
		{ NULL,       NULL,       NULL,       0,            False,       -1 },
	};

The code in dwm.c will check that the `class` element is not NULL before any
matching is done.

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

This code assumes the rules array has at least one element, and that the first
rule that does not match will apply to all window classes. Therefore, the rule
we just made, is the default rule for all new windows and therefore it is
important you set the `tags mask` and `isfloating` elements correctly.
