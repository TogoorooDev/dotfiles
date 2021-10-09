/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#1f1f1f";
static const char normbgcolor[]     = "#1f1f1f";
static const char normfgcolor[]     = "#c0c0c0";
static const char selbordercolor[]  = "#ff8000";
static const char selbgcolor[]      = "#1f1f1f";
static const char selfgcolor[]      = "#ff8000";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

/* include(s) depending on the tags array */
#include "flextile.h"

/* include(s) defining functions */
#include "keymodes.pre.h"

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 4,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.6; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */
static const int layoutaxis[] = {
	1,    /* layout axis: 1 = x, 2 = y; negative values mirror the layout, setting the master area to the right / bottom instead of left / top */
	2,    /* master axis: 1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle) */
	2,    /* stack axis:  1 = x (from left to right), 2 = y (from top to bottom), 3 = z (monocle) */
};

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },    /* first entry is default */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *haltcmd[]  = { "sudo", "halt", NULL };
static const char *helpcmd[]  = { "uxterm", "-e", "man", "dwm", NULL };
static const char *sleepcmd[] = { "sudo", "pm-suspend", NULL };
static const char *termcmd[]  = { "uxterm", NULL };
static const char *audio1cmd[]  = { "amixer", "--quiet", "sset", "Master", "1+", NULL };
static const char *audio2cmd[]  = { "amixer", "--quiet", "sset", "Master", "1-", NULL };
static const char *audio3cmd[]  = { "amixer", "--quiet", "sset", "Master", "toggle", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,                           XK_Super_L, setkeymode,     {.ui = COMMANDMODE} },
	{ 0,          XF86XK_AudioRaiseVolume,     spawn,          {.v = audio1cmd} },
	{ 0,          XF86XK_AudioLowerVolume,     spawn,          {.v = audio2cmd} },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = audio3cmd} },
	{ MODKEY,                       XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Up,     focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
};

static const int h_master[] = {+1, 2, 2};
static const int j_master[] = {-2, 1, 1};
static const int k_master[] = {+2, 1, 1};
static const int l_master[] = {-1, 2, 2};

static Key cmdkeys[] = {
	/* modifier       keys               function       argument */
	{ 0,              XK_Escape,         clearcmd,      {0} },
	{ ControlMask,    XK_c,              clearcmd,      {0} },
	{ 0,              XK_i,              setkeymode,    {.ui = INSERTMODE} },
	{ 0,              XF86XK_Standby,    spawn,         {.v = sleepcmd} },
};
static Command commands[] = {
	/* modifier (4 keys)                          keysyms (4 keys)                                function         argument */
	{ {0,           0,          0,         0},    {XK_g,      XK_t,     0,         0},            adjacentview,    {.i = +1} },
	{ {0,           ShiftMask,  0,         0},    {XK_g,      XK_t,     0,         0},            adjacentview,    {.i = -1} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_c,     0,         0},            closewindow,     {0} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_h,     0,         0},            focustiled,      {.i = -1} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_j,     0,         0},            focustiled,      {.i = +2} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_k,     0,         0},            focustiled,      {.i = -2} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_l,     0,         0},            focustiled,      {.i = +1} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_h,     0,         0},            setmaster,       {.v = h_master} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_j,     0,         0},            setmaster,       {.v = j_master} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_k,     0,         0},            setmaster,       {.v = k_master} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_l,     0,         0},            setmaster,       {.v = l_master} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_o,     0,         0},            setlayout,       {.v = &layouts[0]} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_o,     0,         0},            onlyclient,      {0} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_s,     0,         0},            split,           {.ui = 2} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_t,     0,         0},            adjacenttag,     {.i = +1} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_t,     0,         0},            adjacenttag,     {.i = -1} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_v,     0,         0},            split,           {.ui = 1} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_x,     0,         0},            exchangewindow,  {.i = +1} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_x,     0,         0},            exchangewindow,  {.i = -1} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_w,     0,         0},            focuswindow,     {.i = +1} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_w,     0,         0},            focuswindow,     {.i = -1} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_0,     0,         0},            setmfact,        {.f = +1.50} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_less,  0,         0},            resizemaster,    {.f = -10.05} },
	{ {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_less,  0,         0},            resizemaster,    {.f = +10.05} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_minus, 0,         0},            resizemaster,    {.f = -20.05} },
	{ {ControlMask, 0,          0,         0},    {XK_w,      XK_plus,  0,         0},            resizemaster,    {.f = +20.05} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_e,     0,         0},            spawn,           {.v = dmenucmd} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_o,     0,         0},            spawn,           {.v = dmenucmd} },
	{ {ShiftMask,   ShiftMask,  0,         0},    {XK_period, XK_1,     0,         0},            spawn,           {.v = termcmd} },
	{ {ControlMask, 0,          ShiftMask, 0},    {XK_w,      XK_1,     XK_t,      0},            tag,             {.ui = 1 << 0} },
	{ {ControlMask, 0,          ShiftMask, 0},    {XK_w,      XK_2,     XK_t,      0},            tag,             {.ui = 1 << 1} },
	{ {ControlMask, 0,          ShiftMask, 0},    {XK_w,      XK_3,     XK_t,      0},            tag,             {.ui = 1 << 2} },
	{ {ControlMask, 0,          ShiftMask, 0},    {XK_w,      XK_4,     XK_t,      0},            tag,             {.ui = 1 << 3} },
	{ {ControlMask, 0,          ShiftMask, 0},    {XK_w,      XK_5,     XK_t,      0},            tag,             {.ui = 1 << 4} },
	{ {0,           0,          0,         0},    {XK_1,      XK_g,     XK_t,      0},            view,            {.ui = 1 << 0} },
	{ {0,           0,          0,         0},    {XK_2,      XK_g,     XK_t,      0},            view,            {.ui = 1 << 1} },
	{ {0,           0,          0,         0},    {XK_3,      XK_g,     XK_t,      0},            view,            {.ui = 1 << 2} },
	{ {0,           0,          0,         0},    {XK_4,      XK_g,     XK_t,      0},            view,            {.ui = 1 << 3} },
	{ {0,           0,          0,         0},    {XK_5,      XK_g,     XK_t,      0},            view,            {.ui = 1 << 4} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_h,     XK_Return, 0},            spawn,           {.v = helpcmd} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_q,     XK_Return, 0},            quit,            {0} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_d,      XK_Return},    killclient,      {0} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = +1} },
	{ {ShiftMask,   0,          ShiftMask, 0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = -1} },
	{ {ShiftMask,   0,          ShiftMask, 0},    {XK_period, XK_q,     XK_1,      XK_Return},    spawn,           {.v = haltcmd} },
	{ {ShiftMask,   0,          0,         0},    {XK_period, XK_g,     XK_o,      XK_Return},    togglebar,       {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
};

/* include(s) depending on the configuration variables */
#include "keymodes.post.h"
