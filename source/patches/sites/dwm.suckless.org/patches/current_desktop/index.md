current\_desktop
================

Description
-----------
Sets \_NET\_NUMBER\_OF\_DESKTOPS and \_NET\_CURRENT\_DESKTOP on root to
appropriate values. Note that 'appropriate' for these values don't make sense
as xprop -root output, since dwm uses them at bitwise but xprop displays them
in base ten. In other words, if you have 4 desktops,
\_NET\_NUMBER\_OF\_DESKTOPS is actualy 0b1111 but xprop displays this as 15.
I'm ok with this, because the end-user (program, script, w/e) can always parse
this appropriately. The same goes for \_NET\_CURRENT\_DESKTOP: if you have
desktops 1 and 3 selected, the value is 0b1010, but xprop shows this as 10.
This isn't a problem.

I should note that in this case, \_NET\_NUMBER\_OF\_DESKTOPS does not exactly
conform to EWMH specifications: in reality, there are many more 'desktops' than
15 (in the above example), as any combination of 1, 2, 3 or 4 of the availables
tags can be considered one desktop. \_CURRENT\_DESKTOP will, however, always be
less that \_NET\_NUMBER\_OF\_DESKTOPS, so I'm happy with that.

I wrote this patch mainly for myself, as I have a script for tabbed that uses
it (I will upload this later). I am open to feedback/contstructive criticism.
Email is at the bottom.

Download
--------
* [dwm-current\_desktop-5.8.2.diff](dwm-current_desktop-5.8.2.diff) (dwm 2010604)

Author
------
* Wolfgang S. - ezzieyguywuf at gmail period com
