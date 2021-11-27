inplacerotate
=============

Description
-----------
This patch provides keybindings to perform 'in place' rotations (in that
clients are rotated but the focus position in the stack is unchanged).

The argument for the `inplacerotate` function affects the behavior of
the rotation as follows:

*-1/+1* -> CCW/CW inplace master OR stack rotation (based on focus position)

Shifts the ordering of clients in the master / stack area without worrying
clients will transfer between the master / stack (nmaster) boundry. If
your current focus is in the master area, clients in the master rotate and
stack clients are left alone. And inversely, if you're focused on a client
in the stack, stack clients are rotated but master clients are left alone.

*-2/+2* -> CCW/CW inplace all clients rotation.


Download
--------
* [dwm-inplacerotate-6.2.diff](dwm-inplacerotate-6.2.diff)

Authors
-------
* Miles Alan - <m@milesalan.com>
