attachbelow
===========

Description
-----------
Make new clients attach below the selected client, instead of
always becoming the new master. Inspired heavily from the 
[atttachabove](/patches/attachabove/) patch.

A new version of the patch also allows this behaviour to be toggled.
I have this bound to mod+tab, over-riding the default behaviour of
mod+tab. This change is not included in the patch.

Example Configuration
---------------------

Add the following to your keys array to bind mod+tab to toggle attach below.

	{ MODKEY,                       XK_Tab,           toggleAttachBelow,           {0} },


Download
--------
* [dwm-attachbelow-toggleable-6.2.diff](dwm-attachbelow-toggleable-6.2.diff)
* [dwm-attachbelow-6.2.diff](dwm-attachbelow-6.2.diff)

Authors
-------
* Jonathan Hodgson - <git@jonathanh.co.uk>
