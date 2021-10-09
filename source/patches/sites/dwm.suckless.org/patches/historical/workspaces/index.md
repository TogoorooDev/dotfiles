Workspaces
==========
Adds to dwm the functionality of remembering tagset, layout and mfact for a
given number of workspaces. You can also define preconfigured workspaces.

Code
----
Insert this code before your keys definitions in config.h or in an included .c
file:

	typedef struct Workspace Workspace;
	struct Workspace {
		unsigned int tagset;
		Layout *lt;
		float mfact;
	};
	
	static Workspace workspaces[] = {
		/* tagset						layout			fact */
		{ (1 << 0),						&layouts[0],	0.55},
		{ (1 << 0) | (1<< 8),			&layouts[0],	0.75},
		{ (1 << 0) | (1<< 1) | (1<< 8),	&layouts[1],	0},
		{ (1<< 8),						&layouts[2],	0},
	};
	
	static unsigned int ws = 0;
	
	static void
	setws(int nws) {
		workspaces[ws].tagset = tagset[seltags];
		workspaces[ws].lt = lt[sellt];
		workspaces[ws].mfact = (workspaces[ws].lt == &layouts[0]) ? mfact : 0;
		if(nws < LENGTH(workspaces))
			ws = nws;
		if(workspaces[ws].tagset) {
			tagset[seltags] = workspaces[ws].tagset;
			lt[sellt] = workspaces[ws].lt;
			if(workspaces[ws].mfact != 0)
				mfact = workspaces[ws].mfact;
			arrange();
		}
	}
	
	static void
	prevws(const Arg *arg) {
		setws((ws == 0) ? LENGTH(workspaces) - 1 : ws - 1);
	}
	
	static void
	nextws(const Arg *arg) {
		setws((ws == LENGTH(workspaces) - 1) ? 0 : ws + 1);
	}

And then, you can define keys:

		{ MODKEY,                       XK_Tab,    nextws,         {0} },
		{ MODKEY|ShiftMask,             XK_Tab,    prevws,         {0} },

Or mouse buttons:

		{ ClkTagBar,            0,              Button4,        prevws,         {0} },
		{ ClkTagBar,            0,              Button5,        nextws,         {0} },

Comments
--------
It is so easy to change the viewed tags, layout and mfact in dwm than having
artifacts to remember them are not necessary, this patch is just an example of
how it could be implemented, but it won't be updated for future releases.

It should be easy to add to the workspaces the possibility to remember bar
position too.

It is not necessary to define all your workspaces (or any of them). You can
perfectly do:

	static Workspace workspaces[16] = {
		/* tagset						layout			fact */
		{ (1 << 0),						&layouts[0],	0.55},
		{ (1 << 0) | (1<< 8),			&layouts[0],	0.75},
	};

or:

	static Workspace workspaces[16];

Authors
-------
* [Jesus Galan (yiyus)](mailto:yiyu dot jgl at gmail>) (aug 30 21:41:42 CEST 2008)*
