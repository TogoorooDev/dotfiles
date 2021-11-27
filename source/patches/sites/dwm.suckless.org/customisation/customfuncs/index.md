Custom functions in config.h
============================
You don't need to write complex patches to config dwm, some custom functions
and sensible key and button definitions in config.h let you turn dwm into
whatever you want without messing with dwm.c.

Example of config.h
-------------------
This example is for people who prefer to control dwm with the mouse (for dwm
5.1):

	/* See LICENSE file for copyright and license details. */
	
	/* appearance */
	static const char font[]            = "-*-terminus-bold-r-normal-*-14-*-*-*-*-*-*-*";
	static const char normbordercolor[] = "#cccccc";
	static const char normbgcolor[]     = "#eeeeee";
	static const char normfgcolor[]     = "#000000";
	static const char selbordercolor[]  = "#0066ff";
	static const char selbgcolor[]      = "#eeeeee";
	static const char selfgcolor[]      = "#0066ff";
	static unsigned int borderpx        = 3;        /* border pixel of windows */
	static unsigned int snap            = 32;       /* snap pixel */
	static Bool showbar                 = True;     /* False means no bar */
	static Bool topbar                  = True;     /* False means bottom bar */
	static Bool readin                  = True;     /* False means do not read stdin */
	
	/* tagging */
	const char tags[][MAXTAGLEN] = { "1", "2", "3", "4", "5", "w" };
	
	static Rule rules[] = {
		/* class      instance    title       tags mask     isfloating   monitor */
		{ "acme",      NULL,       NULL,       1 << 2,       False,       -1 },
		{ "Acroread",  NULL,       NULL,       0,            True,        -1 },
		{ "Gimp",      NULL,       NULL,       0,            True,        -1 },
		{ "GQview",    NULL,       NULL,       0,            True,        -1 },
		{ "MPlayer",   NULL,       NULL,       0,            True,        -1 },
		{ "Navigator", NULL,       NULL,       1 << 5,       False,       -1 },
	};
	
	/* layout(s) */
	static float mfact      = 0.65;
	static Bool resizehints = False;     /* False means respect size hints in tiled resizals */
	
	static Layout layouts[] = {
		/* symbol     arrange function */
		{ "[]=",      tile }, /* first entry is default */
		{ "< >",      NULL }, /* no layout function means floating behavior */
		{ "[ ]",      monocle },
	};
	
	/* custom functions declarations */
	static void focusstackf(const Arg *arg);
	static void setltor1(const Arg *arg);
	static void toggletorall(const Arg *arg);
	static void togglevorall(const Arg *arg);
	static void vieworprev(const Arg *arg);
	static void warptosel(const Arg *arg);
	static void zoomf(const Arg *arg);
	
	/* key definitions */
	#define MODKEY Mod1Mask
	#define TAGKEYS(KEY,TAG) \
		{ MODKEY,                       KEY,      vieworprev,     {.ui = 1 << TAG} }, \
		{ MODKEY|ControlMask,           KEY,      togglevorall,   {.ui = 1 << TAG} }, \
		{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
		{ MODKEY|ControlMask|ShiftMask, KEY,      toggletorall,   {.ui = 1 << TAG} },
	
	/* helper for spawning shell commands in the pre dwm-5.0 fashion */
	#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
	
	/* commands */
	static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
	static const char *termcmd[]  = { "uxterm", NULL };
	
	static Key keys[] = {
		/* modifier                     key        function        argument */
		{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
		{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
		{ MODKEY,                       XK_b,      togglebar,      {0} },
		{ MODKEY,                       XK_j,      focusstackf,    {.i = +1 } },
		{ MODKEY,                       XK_j,      warptosel,      {0} },
		{ MODKEY,                       XK_k,      focusstackf,    {.i = -1 } },
		{ MODKEY,                       XK_k,      warptosel,      {0} },
		{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
		{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
		{ MODKEY,                       XK_Return, zoomf,          {0} },
		{ MODKEY,                       XK_Return, warptosel,      {0} },
		{ MODKEY,                       XK_Tab,    view,           {0} },
		{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
		{ MODKEY,                       XK_space,  setltor1,       {.v = &layouts[0]} },
		{ MODKEY|ShiftMask,             XK_space,  setltor1,       {.v = &layouts[2]} },
		{ MODKEY,                       XK_0,      vieworprev,     {.ui = ~0 } },
		{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
		TAGKEYS(                        XK_1,                      0)
		TAGKEYS(                        XK_2,                      1)
		TAGKEYS(                        XK_3,                      2)
		TAGKEYS(                        XK_4,                      3)
		TAGKEYS(                        XK_5,                      4)
		TAGKEYS(                        XK_w,                      5)
		{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	};
	
	/* button definitions */
	/* click can ClkTagBar, ClkTagButton,
	 * ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
	static Button buttons[] = {
		/* click                event mask      button          function        argument */
		{ ClkLtSymbol,          0,              Button1,        setltor1,       {.v = &layouts[0]} },
		{ ClkLtSymbol,          0,              Button2,        setmfact,       {.f = 1.65} },
		{ ClkLtSymbol,          0,              Button3,        setltor1,       {.v = &layouts[2]} },
		{ ClkLtSymbol,          0,              Button4,        setmfact,       {.f = +0.05} },
		{ ClkLtSymbol,          0,              Button5,        setmfact,       {.f = -0.05} },
		{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
		{ ClkStatusText,        Button3Mask,    Button1,        killclient,     {0} },
		{ ClkWinTitle,          0,              Button1,        warptosel,      {0} },
		{ ClkWinTitle,          0,              Button1,        movemouse,      {0} },
		{ ClkWinTitle,          0,              Button2,        zoomf,          {0} },
		{ ClkWinTitle,          0,              Button3,        resizemouse,    {0} },
		{ ClkWinTitle,          0,              Button4,        focusstackf,    {.i = -1 } },
		{ ClkWinTitle,          0,              Button5,        focusstackf,    {.i = +1 } },
		{ ClkRootWin,           0,              Button1,        warptosel,      {0} },
		{ ClkRootWin,           0,              Button1,        movemouse,      {0} },
		{ ClkRootWin,           0,              Button3,        resizemouse,    {0} },
		{ ClkRootWin,           0,              Button4,        focusstackf,    {.i = -1 } },
		{ ClkRootWin,           0,              Button5,        focusstackf,    {.i = +1 } },
		{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
		{ ClkClientWin,         MODKEY,         Button2,        zoomf,          {0} },
		{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
		{ ClkTagBar,            0,              Button1,        vieworprev,     {0} },
		{ ClkTagBar,            0,              Button3,        togglevorall,   {0} },
		{ ClkTagBar,            0,              Button4,        focusstackf,    {.i = -1 } },
		{ ClkTagBar,            0,              Button5,        focusstackf,    {.i = +1 } },
		{ ClkTagBar,            Button2Mask,    Button1,        tag,            {0} },
		{ ClkTagBar,            Button2Mask,    Button3,        toggletorall,   {0} },
	};
	
	/* custom functions */
	void
	focusstackf(const Arg *arg) {
		Client *c = NULL, *i;
	
		if(!sel)
			return;
		if(lt[sellt]->arrange) {
			if (arg->i > 0) {
				for(c = sel->next; c && (!ISVISIBLE(c) || c->isfloating != sel->isfloating); c = c->next);
				if(!c)
					for(c = clients; c && (!ISVISIBLE(c) || c->isfloating == sel->isfloating); c = c->next);
			}
			else {
				for(i = clients; i != sel; i = i->next)
					if(ISVISIBLE(i) && i->isfloating == sel->isfloating)
						c = i;
				if(!c)
					for(i =  sel; i; i = i->next)
						if(ISVISIBLE(i) && i->isfloating != sel->isfloating)
							c = i;
			}
		}
		if(c) {
			focus(c);
			restack();
		}
		else
			focusstack(arg);
	}
	
	void
	setltor1(const Arg *arg) {
		Arg a = {.v = &layouts[1]};
	
		setlayout((lt[sellt] == arg->v) ? &a : arg);
	}
	
	void
	toggletorall(const Arg *arg) {
		Arg a;
	
		if(sel && ((arg->ui & TAGMASK) == sel->tags)) {
			a.ui = ~0;
			tag(&a);
		}
		else
			toggletag(arg);
	}
	
	void
	togglevorall(const Arg *arg) {
		Arg a;
	
		if(sel && ((arg->ui & TAGMASK) == tagset[seltags])) {
			a.ui = ~0;
			view(&a);
		}
		else
			toggleview(arg);
	}
	
	void
	vieworprev(const Arg *arg) {
		Arg a = {0};
	
		view(((arg->ui & TAGMASK) == tagset[seltags]) ? &a : arg);
	}
	
	void
	warptosel(const Arg *arg) {
		XEvent ev;
	
		if(sel)
			XWarpPointer(dpy, None, sel->win, 0, 0, 0, 0, 0, 0);
		XSync(dpy, False);
		while(XCheckMaskEvent(dpy, EnterWindowMask, &ev));
	}
	
	void
	zoomf(const Arg *arg) {
		if(sel && (lt[sellt]->arrange != tile || sel->isfloating)) 
			togglefloating(NULL);
		else
			zoom(NULL);
	}

Usage of the above configuration
--------------------------------
In case you want to try this configuration there are some differences with the
default dwm config to be taken into account. Mouse actions will be explained
later, keys have similar behaviour. There are other small changes, but the
config.h file should be pretty straightforward.

### Tagging

In the tag buttons:

* B1: view a tag, trying to view the selected tagset will result in a change to
  the previous one.
* B3: toggle a tag, trying to toggle the last selected tag will result in
  viewing all tags.
* B2+B1: assign tag to the sel client.
* B2+B3: toggle tag for the sel client, trying to toggle the last tag will
  result in assigning all tags.

### Layouts

In the layout symbol:

* B1: toggle between tiled and floating layout.
* B3: toggle between monocle and floating layout.
* Wheel: set master factor (B2 to go back to the default value).

### Focusing/Moving/Resizing

in the status bar, the root window, or the selected window (with Mod pressed)

* Wheel to focus prev/next client. Floating clients will just be focused after
  the tiled ones.
* B1 to move (the pointer will be wrapped to the upper-left corner if
  necessary).
* B3 to resize (the pointer will be wrapped to the bottom-right corner).
* B2 to zoom or toggle floating status if zooming is not possible.

### Closing windows

* B3+B1 in the status message.

Author
------
* [Jesus Galan (yiyus)](mailto:yiyu dot jgl at gmail>) (vie ago 22 19:53:32 CEST 2008)
