swallow
=======

Description
-----------
This patch adds "window swallowing" to dwm as known from Plan 9's windowing
system `rio`.

Clients marked with `isterminal` in config.h swallow a window opened by any
child process, e.g. running `xclock` in a terminal. Closing the `xclock` window
restores the terminal window in the current position.

This patch helps users spawning a lot of graphical programs from their command
line by avoiding cluttering the screen with many unusable terminals. Being deep
down in a directory hierarchy just does not make the use of dmenu feasible.

Dependencies
------------
* libxcb
* Xlib-libxcb
* xcb-res

These dependencies are needed due to the use of the latest revision of the X
Resource Extension which is unsupported in vanilla Xlib.

Download
--------
* [dwm-swallow-20201211-61bb8b2.diff](dwm-swallow-20201211-61bb8b2.diff)
* [dwm-swallow-20200807-b2de9b0.diff](dwm-swallow-20200807-b2de9b0.diff)
* [dwm-swallow-20200707-8d1e703.diff](dwm-swallow-20200707-8d1e703.diff)
* [dwm-swallow-20200522-7accbcf.diff](dwm-swallow-20200522-7accbcf.diff)
* [dwm-swallow-6.2.diff](dwm-swallow-6.2.diff)
* [dwm-swallow-20170909-ceac8c9.diff](dwm-swallow-20170909-ceac8c9.diff)
* [dwm-swallow-6.1.diff](dwm-swallow-6.1.diff)
* [dwm-swallow-20160717-56a31dc.diff](dwm-swallow-20160717-56a31dc.diff)

Notes
-----
The window swallowing functionality requires `dwm` to walk the process tree,
which is an inherently OS-specific task. Please contact one of the authors
if you would like to help expand the list of supported operating systems.

Only terminals created by local processes can swallow windows, and only windows
created by local processes can be swallowed.

Authors
-------
* Rob King - <jking@deadpixi.com>
* Laslo Hunhold - <dev@frign.de> (6.1, git port)
* Petr Šabata - <contyk@redhat.com> (bugfixes)
* wtl - <wtl144000@gmail.com> (bugfixes)
* John Wilkes - <jdwilkesx@gmail.com> (bugfixes)
* Ben Raskin - <ben@0x1bi.net> (OpenBSD support)
