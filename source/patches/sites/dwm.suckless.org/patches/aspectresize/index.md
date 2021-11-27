aspectresize
============

Description
-----------
This patch you to resize the window with its aspect ratio remain constant, use
moveresize patch for manual resize.

Usage
-----
1. Put the following `aspectresize()` function somewhere in your `dwm.c`,
  **after** the line which includes the config.h file:

        void
        aspectresize(const Arg *arg) {
        	/* only floating windows can be moved */
        	Client *c;
        	c = selmon->sel;
        	float ratio;
        	int w, h,nw, nh;
        
        	if (!c || !arg)
        		return;
        	if (selmon->lt[selmon->sellt]->arrange && !c->isfloating)
        		return;
        
        	ratio = (float)c->w / (float)c->h;
        	h = arg->i;
        	w = (int)(ratio * h);
        
        	nw = c->w + w;
        	nh = c->h + h;
        
        	XRaiseWindow(dpy, c->win);
        	resize(c, c->x, c->y, nw, nh, True);
        }
 

2. Add a aspectresize() function definition in dwm.c below the line:
	static void aspectresize(const Arg *arg);

3. You can use Mod+Shift+j to increase size and Mod+Shift+k to decrease the size of client
   which respects client's aspect ratio:

	{ MODKEY|ShiftMask,             XK_j,      aspectresize,   {.i = +24} },
	{ MODKEY|ShiftMask,             XK_k,      aspectresize,   {.i = -24} },

Download
--------
* [dwm-aspectresize-6.2.diff](dwm-aspectresize-6.2.diff)

Authors
-------
* Dhaval Patel - <dhavalpatel32768@gmail.com>
