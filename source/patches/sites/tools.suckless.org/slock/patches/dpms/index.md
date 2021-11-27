DPMS
====

Description
-----------
This patch interacts with the Display Power Management Signaling and
automatically turns off the monitor after a configurable time. The monitor is
reactivated by a keystroke or moving the mouse.

Notes
-----
The time until the monitor is disabled is configurable as `monitortime` in the
`config.h` file in seconds.

Download
--------
* [slock-dpms-1.4.diff](slock-dpms-1.4.diff)

Authors
-------
* Alvar Penning <post@0x21.biz>
