anybar
======

Description
-----------
**dwm-anybar** is a patch for dwm that enables dwm to manage external status
bars such as lemonbar and polybar. dwm treats the external bar as it would its
own, so all regular dwm commands such as togglebar affect the external bar in
the same way.

The project is being managed and developed on this GitHub
[repo](https://github.com/mihirlad55/dwm-anybar). If you discover any bugs or
patch incompatabilities, feel free to create an issue there.


Configuration
-------------
    static const int showbar       = 1;          /* 0 means no bar */
    static const int topbar        = 1;          /* 0 means bottom bar */
    static const int usealtbar     = 1;          /* 1 means use non-dwm status bar */
    static const char *altbarclass = "Polybar";  /* Alternate bar class name */

`showbar` and `topbar` affect the external status bar as it would dwm's status
bar. `showbar` must be `1` to show the external bar. `topbar` must be set
appropriately as well based on if the external bar is docked at the bottom or
the top of the screen. The patch only supports bars docked at the top/bottom of
the monitor.

`usealtbar` must be set to `1` to use an external status bar, otherwise dwm's
own bar will be enabled.

`altbarclass` must be set to the class name of the external status bar for dwm
to differentiate it from regular windows. The class name of the bar can be found
using `xprop`

	xprop(1):
	 WM_CLASS(STRING) = instance, class
	                              ^^^^^
	                               altbarclass should be set to this
	 WM_NAME(STRING) = title


Polybar Tray Fix
----------------
Since polybar's tray is handled as a separate window and is populated slowly, it
is difficult to manage. There is a `polybar-tray-fix` version of the patch that
allows dwm to manage the tray. The tray isn't actually managed until the
togglebar command is called, but it fixes the issue where toggling the bar would
not hide the tray.

This version of the patch adds `alttrayname` to `config.def.h` which is already
set to the correct value.


Download
--------
* Anybar Patch v1.1.0:
  [dwm-anybar-20200810-bb2e722.diff](dwm-anybar-20200810-bb2e722.diff)
* Anybar Patch v1.0.3 to v1.1.0 Update:
  [dwm-anybar-v1.0.3-to-v1.1.0.diff](dwm-anybar-v1.0.3-to-v1.1.0.diff)
* Anybar Patch (with Polybar tray fix) v1.1.0:
  [dwm-anybar-polybar-tray-fix-20200810-bb2e722.diff](dwm-anybar-polybar-tray-fix-20200810-bb2e722.diff)

The latest releases of the patch will always be available first on the project
[Releases](https://github.com/mihirlad55/dwm-anybar/releases) page. There are
also "update" patches to update from previous versions of the patch.


Related Projects
----------------
* [polybar-dwm-module](https://github.com/mihirlad55/polybar-dwm-module)
  works better with this patch


Authors
-------
* Mihir Lad - <mihirlad55 at gmail>
