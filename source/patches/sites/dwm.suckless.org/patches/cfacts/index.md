cfacts
======

Description
-----------
This patch provides the ability to assign different weights to clients in their
respective stack in tiled layout. It implements a new function setcfact which
will modify the cfact-value for the currently selected client. It accepts the
following values:

* A positive float to increase a clients weight, thus increasing the space the
  client is allocated in its current stack.
* A negative float to decrease a clients weight, thus decreasing the space the
  client is allocated in its current stack.
* A zero-value float to reset a clients weight to default.

Default cfact-value for each client is 1.0. If a client is assigned a cfact
value of 0.5 it will be allocated half of the space other clients would be
allocated. If a client is assigned a cfact value of 2.0 it will be allocated
twice the space other clients would be allocated.

The following illustrates the behavior. The clients cfact-values are
represented by floats inside the clients rectangles.

	+---------------------+
	|          |   0.5    |
	|   1.0    +----------+
	+----------+          |
	|          |   1.0    |
	|          +----------+
	|   2.0    |          |
	|          |   1.0    |
	+----------+----------+

Default key bindings
--------------------
	 Key     Argument   Description
	-----------------------------------
	 Mod-H   +0.25      Increase cfact
	 Mod-L   -0.25      Decrease cfact
	 Mod-O    0.00      Reset cfact

Download
--------
* [dwm-cfacts-6.1.diff](dwm-cfacts-6.1.diff)
* [dwm-cfacts-6.2.diff](dwm-cfacts-6.2.diff)
* [dwm-cfacts-6.2-1.diff](dwm-cfacts-6.2-1.diff)
* [dwm-cfacts-20200913-61bb8b2.diff](dwm-cfacts-20200913-61bb8b2.diff)

Additional layouts with cfacts
------------------------------
Just patch these on top of the original cfacts patch.

* [dwm-cfacts\_bottomstack-6.2.diff](dwm-cfacts_bottomstack-6.2.diff)
* [dwm-cfacts\_centeredmaster-6.2.diff](dwm-cfacts_centeredmaster-6.2.diff)
* [dwm-cfacts\_deck-6.2.diff](dwm-cfacts_deck-6.2.diff)

Author
------
* Patrick Steinhardt (pks) <ps@pks.im>
* Aaron Duxler <aaron@duxler.xyz> - Additional layouts bottomstack + centeredmaster + deck
* mss <mss@waifu.club> - dwm-6.2 port. 
* Tobias Giess <tobias.giess@gmail.com> - Fix dwm-6.2 port not working on clients in the stack
