tab
===

Description
-----------
Transforms the monocle layout into a ''tabbed'' layout if more than one window
is present on the monocle view. Navigating from window to window is done by
clicking on the window tabs or using the usual Mod1-j, Mod1-k keys. The tabs
are arranged in a bar on top or at bottom of the screen, which can also be
displayed in the other layouts than monocle. Three display modes can be
selected at run time, auto display, permanent display and no display. In
permanent mode the tab bar is always display independently of the layout, while
in the auto mode it is displayed only with the monocle layout and in presence
of several windows.

This patch can be used as an alternative to the
[tabbed](//tools.suckless.org/tabbed/) tool. It differs in two ways: the
''tab'' feature is limited to the monocle mode; it works with any application
without requiring to support the XEmbed protocol nor to define in advance the
set of applications to be supported.

Usage
-----
With the default configuration, use the key combination Mod1-w to toggle the
tab bar display. Switch focus to a window with a mouse left-click on its tab or
by using the usual Mod1-j, Mod1-k commands. Usage is also documented in the dwm
man page once the patch is applied.

The selected view (''tag'') is reminded at the right corner of the tab bar.
This feature is mainly meant to be used when the standard status bar is
disabled. In case of a multi-tag view three dots are displayed without
additional details.

Configuration and Installation
------------------------------

### Quick installation

#### Using the default configuration file

* Make sure the directory where you build dwm does not contain a config.h file;
* Apply the patch;
* Run make and make install.

The bar is displayed only with monocle layout when the view contains more than
one window. The section "More Options" explains how to add more display
options.

#### Using an existing customised configuration file

* Apply the patch;
* Add the following lines to your config.h dwm configuration file:

       /*   Display modes of the tab bar: never shown, always shown, shown only in  */
       /*   monocle mode in presence of several windows.                            */
       /*   A mode can be disabled by moving it after the showtab_nmodes end marker */
       enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
       static const int showtab            = showtab_auto; /* Default tab bar show mode  */
	       static const Bool toptab            = True;         /* False means bottom tab bar */

If you use the combined pertag+tab patch, include also (adapt the number of '0'
to your `tags` array configuration):

	/* default layout per tags */
	/* The first element is for all-tag view, following i-th element corresponds to */
	/* tags[i]. Layout is referred using the layouts array index.*/
	static int def_layouts[1 + LENGTH(tags)]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
* Run make and make install.

The tab bar is displayed only with the monocle layout when the view contains
more than one window. The Mod1-w key and the mouse support are not included in
this configuration. Activation of these options is explained in the next
section.

### More Options

Pressing the key Mod1-w will cycle over the display modes of the tab bar
described below with the following element added to the `keys` array:

	{ MODKEY, XK_w, tabmode, {-1} }

Selection of a window by a mouse left-click on its tab is enabled by adding the
following element to the `buttons` array:

	{ ClkTabBar, 0, Button1, focuswin, {0} },

An example on how to insert these lines can be found in the default config file
template, config.def.h.

The tab bar includes three display options: always, never, auto. In auto mode,
the tab bar is displayed only with the monocle layout and when the view
contains more than one window. The modes available at run time can be selected
by changing the order of the elements in the `showtab_mode` enum of the
config.h configuration file: the modes before `showtab_nmodes` are enabled, the
ones after are disabled. The default mode is specified in the `showtab`
variable, it must be one of the enabled modes.

Note: keyboard shortcuts to switch to a given display mode can be defined by
using the `tabmode` function like in the definition of the `Mod1-w` key
provided above and passing as argument the display mode (`showtab_never`,
`showtab_always`, `showtab_auto`) instead of -1.

The tab bar can be displayed on top or at bottom of the screen, which is
controlled by the 'toptab' variable. If the tab bar is displayed at bottom,
then it is recommended to set the variable `resizehints` of the config.h file
to False. This setting prevents possible gap between the windows and the tab
bar. You can find more details about this variable and gap between windows in
the dwm FAQ.

Download
--------
* Tab patch alone
  * For dwm 6.1: [dwm-6.1-tab-v2b.diff](dwm-6.1-tab-v2b.diff)
  * For dwm from the git master branch: [dwm-tab-v2b-20210810-7162335.diff](dwm-tab-v2b-20210810-7162335.diff)
  * For dwm 6.2: [dwm-6.2-tab-v2b.diff](dwm-6.2-tab-v2b.diff)
* Combined patch of tab and the [pertag](../pertag/) patch from Jan Christoph
  Ebersbach.
  * Follow the [link](../pertag/) for the description of this patch and the
    credits. The possibility to define the default layout per view has been added.
  * For dwm 6.1: [dwm-6.1-pertag-tab-v2b.diff](dwm-6.1-pertag-tab-v2b.diff)
  * For dwm from the git master branch:
    [dwm-tab-v2b-pertab-56a31dc.diff](dwm-tab-v2b-pertab-56a31dc.diff)

Change log
----------
* Fixed the standalone tab patch not applying to the current git master.
* **v2b** Fixed in the pertag-tab patch the support for per-tag default layout
  specification. No change in the tab only patch.
* **v2a** Typo corrected in the man page. For the combined pertag-tab patch,
  specification of a default layout per-tag layout was added in the config.h
  configuration file, but it was not taken into account properly. The version v2b
  fixed this issue.
* **v2** First public version.

Authors
-------
* Philippe Gras - `<philippe dot gras at free dot fr>`
* Varun Iyer (6.2 ver) - `<varun_iyer@protonmail.com>`
