canfocusfloating
================

Description
-----------
Patch that allows disabling/enabling focus on floating clients. (when enabled, if you try to focus next/previous client in current tag, all floating clients will be skipped)

* If floating client is selected while toggle is pressed, then master client is focused
* On re-enabling focus, first floating client is focused
* When user toggle floating of new client, if focus on floating clients was disabled, it will be removed

Inspired by [canfocusrule](https://dwm.suckless.org/patches/canfocusrule/) patch

Download
--------
* [dwm-canfocusfloating-20210724-b914109.diff](dwm-canfocusfloating-20210724-b914109.diff)

Authors
-------
* Georgios Oxinos - <oxinosg@gmail.com>
