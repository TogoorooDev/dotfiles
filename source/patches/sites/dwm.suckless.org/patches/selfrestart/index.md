selfrestart
===========

Description
-----------
Restart dwm without the unnecessary dependency of an external script.

Also see [restartsig](../restartsig/).

An alternative might be to put something like this in `~/.xinitrc`:

	while :; do
		ssh-agent dwm
	done

And then just quit/kill `dwm`.

Download
--------
* [dwm-r1615-selfrestart.diff](dwm-r1615-selfrestart.diff)

Implementation & idea
---------------------
* Idea belongs to: [Yu-Jie Lin](https://sites.google.com/site/yjlnotes/notes/dwm)
* The simplified implementation: Barbu Paul - Gheorghe <barbu.paul.gheorghe@gmail.com>
