focusonnetactive
================

Description
-----------
By default, dwm response to client requests to \_NET\_ACTIVE\_WINDOW client
messages by setting the urgency bit on the named window.

This patch activates the window instead.

Both behaviours are legitimate according to the
[cursed spec](https://specifications.freedesktop.org/wm-spec/wm-spec-latest.html#idm140200472702304)

One should decide which of these one should perform based on the message
senders' untestable claims that it represents the end-user. Setting the urgency
bit is the conservative decision. This patch implements the more trusting
alternative.

It also allows dwm to work with `wmctrl -a` and other external window
management utilities.

Download
--------
* [dwm-focusonnetactive-6.2.diff](dwm-focusonnetactive-6.2.diff)
* [dwm-focusonnetactive-2017-12-24-3756f7f.diff](dwm-focusonnetactive-2017-12-24-3756f7f.diff)

Author
------
* [Danny O'Brien](http://www.spesh.com/danny/) <danny@spesh.com>
