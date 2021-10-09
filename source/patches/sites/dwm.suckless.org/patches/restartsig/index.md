restartsig
==========

Description
-----------
dwm can now be restarted via MOD+CTRL+SHIFT+Q or by kill -HUP dwmpid

In addition, a signal handler was added so that dwm cleanly quits by kill -TERM
dwmpid.

Also see [selfrestart](../selfrestart/).

An alternative might be to put something like this in `~/.xinitrc`:

	while :; do
		ssh-agent dwm
	done

And then just quit/kill `dwm`.

Download
--------
* [dwm-restartsig-20180523-6.2.diff](dwm-restartsig-20180523-6.2.diff) (2018-05-23)

Author
------
* cd
