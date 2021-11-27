goback
======

Description
-----------
This patch adds a function named `goback` which allows activating the previously active tagset and binds it to *MODKEY+g*. Unlike dwm's `view` function (bound to *MODKEY+Tab* by default), `goback` registers when you focus another monitor.

Examples
--------
* You are on your first monitor and switch from tag 1 to tag 2. Then `goback` (*MODKEY+g*) brings you back to tag 1 (like *MODKEY+Tab*).
* Next, you focus your third monitor (which is showing tags 3 and 4), no matter if your use your mouse or a shortcut like *MODKEY+comma*. Then `goback` (*MODKEY+g*) brings the focus back to your first monitor (tag 1). Pressing *MODKEY+g* again brings you back to the third monitor (tags 3 and 4).

Download
--------
* [dwm-goback-20201227-61bb8b2.diff](dwm-goback-20201227-61bb8b2.diff)

(Also available at [GitHub](https://github.com/MaxGyver83/dwm-goback))

Author
------
* Max Schillinger - <maxschillinger@web.de>
