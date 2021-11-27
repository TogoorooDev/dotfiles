functionalgaps
==============

Description
-----------
Functionalgaps combines the beautifully simplistic gaps of [fullgaps](../fullgaps) with the non-gaps of [singularborders](../singularborders) and [noborder](../noborder). It is named functionalgaps because, since gaps are purely aesthetic, and therefore not useful whatsoever, this patch adds to their functionality by allowing them to easily be turned *off*.

This patch is also unique because of its out of the box integration with [pertag](../pertag), allowing gaps to be enabled/disabled and sized on a per-tag basis.

Gaps, by default, can be toggled with `[Alt]+[Shift]+[=]`, resized using `[Alt]+[+]` / `[Alt]+[-]`, and reset using `[Alt]+[Shift]+[-]` just like [fullgaps](../fullgaps).

The config variables `startwithgaps` and `gappx` are avaliable to change basic behavior.
The versions supporting pertag also have a feature to set these variables for individual tags.
* Example: setting 'startwithgaps[] = { 1, 0 }' will cause tag 1 to start with gaps, and tag 2 to start without; the set behaviors will loop over any unset tags.

Download
--------
* [dwm-functionalgaps-6.2.diff](dwm-functionalgaps-6.2.diff)
* [dwm-functionalgaps-pertagfunctionality-6.2.diff](dwm-functionalgaps-pertagfunctionality-6.2.diff) (this version comes with pertag support)
* [dwm-functionalgaps+pertag-6.2.diff](dwm-functionalgaps+pertag-6.2.diff) (this version comes with support for pertag, + the patch itself for simplicity's sake)

Author
------
* Timmy Keller <applesrcol8796@gmail.com>
