sshawarespawn
=============

Description
-----------
This patch adds the ability to spawn a new terminal with ssh awareness, meaning
that if your current selected client has an open ssh sesion, a newly created
client will copy the ssh command and execute it. The spawning also carries over
additional flags you have given to ssh. If your current client does not have an
ssh session it executes the provided command.

It works by crawling all of the processes for ssh sessions and traversing the
process tree upwards to check if your current client is a parent of an ssh
session. 

This patch borrows the `winpid` function from the swallow patch. My thanks to:
* Rob King
* Laslo Hunhold
* Petr Šabata
* wtl
* John Wilkes
* Ben Raskin

Depedencies
-----------

* libxcb
* Xlib-libxcb
* xcb-res
* libprocps

Download
--------
* [dwm-sshawarespawn-20201015-61bb8b2.diff](dwm-sshawarespawn-20201015-61bb8b2.diff)
* [dwm-sshawarespawn-6.2.diff](dwm-sshawarespawn-6.2.diff)

Notes
-----
Since the patch relies on walking the process tree, which is OS-specific,
compatibility with other operating systems is not guaranteed. If you want to
help expand the list of supported plattforms please contact me.

Authors
-------
* Fabian Blatz - fabian.blatz at gmail period com
