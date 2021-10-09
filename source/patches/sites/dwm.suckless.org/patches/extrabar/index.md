extrabar
==========

Description
-----------
This patch will enable an extra status bar in dwm in a similar manner to the
dualstatus patch. If the primary status is at the top via `topbar` then the
extra status bar will be placed at the bottom and vice versa.

The status bar text can be set as follows:

	xsetroot -name "top text;bottom text"

Support for an alternative delimiter is available and the delimiter can be
changed by editing the `statussep` variable.

The text can be anchored to the left or right side of the screen by editing
the `extrabarright` variable (20210209 diff only.)

Download
--------
* [dwm-extrabar-6.2.diff](dwm-extrabar-6.2.diff) (5680b) (2019.08.10)
* [dwm-extrabar-6.2-20210209.diff](dwm-extrabar-6.2-20210209.diff) (5639b) (2021.02.09)

Screenshot
----------
a simple extra status bar

![Visual of two status bars](dwm-extrabar.png)

Authors
-------
* Chip Senkbeil - `<chip@senkbeil.org>`
* Finn Rayment - `<finn@rayment.fr>`
