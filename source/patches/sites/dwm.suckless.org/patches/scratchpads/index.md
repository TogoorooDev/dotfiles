scratchpads
===========

Description
-----------
This patch enables multiple scratchpads, each with one asigned window.
This enables the same scratchpad workflow that you have in i3.

Scratchpads are implemented as special tags, whose mask does not
apply to new spawned windows. To assign a window to a scratchpad you
have to set up a rule, as you do with regular tags.

Windows tagged with scratchpad tags can be set floating or not in the
rules array. Most users would probably want them floating (i3 style),
but having them tiled does also perfectly work and might fit better the
DWM approach. In case they are set floating, the patch moves them to the
center of the screen whenever they are shown. The patch can easily be
modified to make this last feature configurable in the rules array (see
the center patch).

The togglescratch function, borrowed from the previous scratchpad patch
and slightly modified, can be used to spawn a registered scratchpad
process or toggle its view. This function looks for a window tagged with
the selected scratchpad tag. If it is found its view is toggled. If it is
not found the corresponding registered command is spawned. The
config.def.h shows three examples of its use to spawn a terminal in the
first scratchpad tag, a second terminal running ranger on the second
scratchpad tag and the keepassxc application to manage passwords on a
third scratchpad tag.

If you prefer to spawn your scratchpad applications from the startup
script, you might opt for binding keys to toggleview instead, as
scratchpads are just special tags (you may even extend the TAGKEYS macro
to generalize the key bindings).



Download
--------
* [dwm-scratchpads-20200414-728d397b.diff](dwm-scratchpads-20200414-728d397b.diff)

Authors
-------
* Christian Tenllado <ctenllado@gmail.com> (2020-04-14)
