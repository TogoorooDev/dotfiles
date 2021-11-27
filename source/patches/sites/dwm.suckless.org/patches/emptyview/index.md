emptyview
=========

Description
-----------
I like my wallpapers. Also i found it kind of unintuitive that you can not
toggle the last tag out of view. So i created a patch to allow no tag at all to
be selected.

With this patch, dwm will start with no tag selected. When you start a client
with no tag rule and no tag selected, it gets opened in the first tag.  

Version 6.2 has a `startontag` option(default 1) which tells dwm to bring  
the first tag in view on launch as usual. 0 means no tag active at start.

Download
--------
* [dwm-emptyview-6.2.diff](dwm-emptyview-6.2.diff) (20/06/2020)
* [dwm-emptyview-6.0.diff](dwm-emptyview-6.0.diff) (1753b) (20130330)

Authors
-------
* MLquest8 (update for 6.2 and config option) (miskuzius at gmail.com)
* Markus Teich - `<teichm at in dot tum dot de>`
