multikey
========

Description
-----------
This patch allows you to use a single key combination to trigger different
functions based on the number of times you press the key combination
consecutively within a short period of time. This is accomplished by modifying 
the `Key` struct to add a new int field `npresses` which can be:

      0 = Trigger keybinding on 1 keypress (ignoring multikey functionality)
      1 = Trigger keybinding on 1 keypress 
      2 = Trigger keybinding on 2 successive keypresess 
      3 = Trigger keybinding on 3 successive keypresess
   ...n = Trigger keybinding on n successive keypresses

The maximum / last value set for the key combination can also be triggered by
holding the key down. 

In the example added to the config.def.h, the tiling layout is set when
Mod+w is tapped once, float layout is set when Mod+w is tapped twice, and
monocole layout is set when Mod+w is tapped three times (or held down).

Download
--------
* [dwm-multikey-6.2.diff](dwm-multikey-6.2.diff)

Authors
-------
* Miles Alan - <m@milesalan.com>
