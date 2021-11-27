taggrid
=======

Description
-----------
This patch adds an ability to place tags in rows like in many other
window managers like xfce ore OpenBox.

Applying
--------
Patch uses drawtagmask flagset to show tags. Two flags can be applied to it:

  	#define DRAWCLASSICTAGS             1 << 0
 
this will make patch to draw classic tags row;

  	#define DRAWTAGGRID                 1 << 1`
  
this will make patch to draw the grid of tags like this:

![grid](taggrid.png)

The patch defines `switchtag` function which handle global shortcuts to
navigate in grid. This function accept unsigned int argument which represents
flagset of next flags:

  	#define SWITCHTAG_UP                1 << 0
  	#define SWITCHTAG_DOWN              1 << 1
  	#define SWITCHTAG_LEFT              1 << 2
  	#define SWITCHTAG_RIGHT             1 << 3
this four defines the direction of moving current tags;

  	#define SWITCHTAG_TOGGLETAG         1 << 4
  	#define SWITCHTAG_TAG               1 << 5
  	#define SWITCHTAG_VIEW              1 << 6
  	#define SWITCHTAG_TOGGLEVIEW        1 << 7

this four defines the behaviour of switching. They will make `switchtag` work
like according functions.

Example
-------
Default config file defines nest:

	{ MODKEY|ControlMask,           XK_Up,     switchtag,      { .ui = SWITCHTAG_UP     | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Down,   switchtag,      { .ui = SWITCHTAG_DOWN   | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Right,  switchtag,      { .ui = SWITCHTAG_RIGHT  | SWITCHTAG_VIEW } },
	{ MODKEY|ControlMask,           XK_Left,   switchtag,      { .ui = SWITCHTAG_LEFT   | SWITCHTAG_VIEW } },

this will simply move set of active tags in specified (`UP`, `DOWN`, `RIGHT` or `LEFT`) direction by pressing `ctrl+alt+ARROW`;

	{ MODKEY|Mod4Mask,              XK_Up,     switchtag,      { .ui = SWITCHTAG_UP     | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|Mod4Mask,              XK_Down,   switchtag,      { .ui = SWITCHTAG_DOWN   | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|Mod4Mask,              XK_Right,  switchtag,      { .ui = SWITCHTAG_RIGHT  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ MODKEY|Mod4Mask,              XK_Left,   switchtag,      { .ui = SWITCHTAG_LEFT   | SWITCHTAG_TAG | SWITCHTAG_VIEW } },

this will move active window in specified direction and perform the action, described above.

Download
--------
* [dwm-6.1-taggrid.diff](dwm-6.1-taggrid.diff) (2014-02-16)
* [dwm-6.2-taggrid.diff](dwm-6.2-taggrid.diff) (2019-08-13)

Author
------
* Yury Shvedov - [shved AT lvk DOT cs DOT msu DOT su](mailto:shved@lvk.cs.msu.su) (or [mestofel13 AT gmail DOT com](mailto:mestofel13@gmail.com)).
* Miles Alan - m@milesalan.com (6.2 port)
