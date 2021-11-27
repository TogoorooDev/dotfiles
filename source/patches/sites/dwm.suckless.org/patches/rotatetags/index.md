rotatetags
======

Description
-----------
This patch provides the ability to rotate the tagset left / right.
It implements a new function rotatetags which modifies the current tagset.
It accepts the following values:

* A positive int to rotate the tagset "up", i.e. +1 moves the selection
  from tag 1 to tag 2.

* A negative int to rotate the tagset "down", i.e. -1 moves the selection
  from tag 2 to tag 1.

If the tag would be shifted off the end, i.e. rotating tag 9 up, it
will rotate back to tag 1.

Default key bindings
--------------------
	 Key        Argument   Description
	-----------------------------------
	 Mod-Right  +1         Rotate tagset "up".
	 Mod-Left   -1         Rotate tagset "down".

Download
--------
* [dwm-rotatetags-6.2.diff](dwm-rotatetags-6.2.diff)
* [dwm-rotatetags-20210723-cb3f58a.diff](dwm-rotatetags-20210723-cb3f58a.diff)

Author
------
* Sam Leonard (tritoke) <tritoke@protonmail.com>
