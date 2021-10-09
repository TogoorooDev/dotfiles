Another focus moving model
==========================

Description
-----------
When a single tag is displayed, calling view() or tag() with it as an argument
is useless. This patch enables moving focus forward with view() calls and
backward with tag() instead of doing nothing. Of course, those who toggle
several tags at time or just have more than 3-4 tags won't benefit much from
such behaviour.

Download
--------
* [dwm-5.2-altmovefocus.diff](http://mkmks.org/files/patches/dwm-5.2-altmovefocus.diff)
