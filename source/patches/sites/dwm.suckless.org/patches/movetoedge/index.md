movetoedge
==========

Description
-----------
This patch adds functionality to move windows to edges easily.

Usage
-----
1. Put the following `movetoedge()` function somewhere in your `dwm.c`,
  **after** the line which includes the config.h file:

	void
	movetoedge(const Arg *arg) {
 		/* only floating windows can be moved */
		Client *c;
		c = selmon->sel;
		int x, y, nx, ny;

		if (!c || !arg)
			return;
		if (selmon->lt[selmon->sellt]->arrange && !c->isfloating)
			return;
		if (sscanf((char *)arg->v, "%d %d", &x, &y) != 2)
			return;
	
		if(x == 0)
			nx = (selmon->mw - c->w)/2;
		else if(x == -1)
			nx = borderpx;
		else if(x == 1)
			nx = selmon->mw - (c->w + 2 * borderpx);
		else
			nx = c->x;
	
		if(y == 0)
			ny = (selmon->mh - (c->h + bh))/2;
		else if(y == -1)
			ny = bh + borderpx;
		else if(y == 1)
			ny = selmon->mh - (c->h + 2 * borderpx);
		else 
			ny = c->y;
	
	
		XRaiseWindow(dpy, c->win);
		resize(c, nx, ny, c->w, c->h, True);
	}

2. Add a movetoedge() function definition in dwm.c below the line:
	static void movetoedge(const Arg *arg);

3. In config file :
	{ MODKEY, 			XK_KP_End,    movetoedge,       {.v = "-1 1" } },
	{ MODKEY, 			XK_KP_Down,   movetoedge,       {.v = "0 1" } },
	{ MODKEY, 			XK_KP_Next,   movetoedge,       {.v = "1 1" } },
	{ MODKEY, 			XK_KP_Left,   movetoedge,       {.v = "-1 0" } },
	{ MODKEY, 			XK_KP_Begin,  movetoedge,       {.v = "0 0" } },
	{ MODKEY, 			XK_KP_Right,  movetoedge,       {.v = "1 0" } },
	{ MODKEY, 			XK_KP_Home,   movetoedge,       {.v = "-1 -1" } },
	{ MODKEY, 			XK_KP_Up,     movetoedge,       {.v = "0 -1" } },
	{ MODKEY, 			XK_KP_Prior,  movetoedge,       {.v = "1 -1" } },

Download
--------
* [dwm-movetoedge-6.2.diff](dwm-movetoedge-6.2.diff)

Authors
-------
* Dhaval Patel - <dhavalpatel32768@gmail.com>
