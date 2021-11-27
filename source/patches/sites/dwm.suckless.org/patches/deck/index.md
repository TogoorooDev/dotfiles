deck layout
===========

Description
-----------
`deck` is a dwm-layout which is inspired by the TTWM window manager.
It applies the monocle-layout to the clients in the stack.
The master-client is still visible. The stacked clients are like
a deck of cards, hence the name.

deck-rmaster
------------
The vanilla patch doesn't respect the master-area which is defined by
the rmaster-patch. To make it work with the rmaster-patch apply the
dwm-deck-rmaster patch on top of the dwm-deck patch.

deck-tilegap
------------
The vanilla patch doesn't work properly with patches which add gaps.
This means that when the deck-layout is activated gaps are omitted.
To make it work with the tilegap-patch apply the dwm-deck-tilegap patch
on top of the dwm-deck patch.

deck-double
------------
This patch variant adds a layout function named doubledeck which is
similar to the deck layout. However, rather then just creating a deck
area in the stack; it also creates a deck area in the master area. This
pairs nicely with the [bartabgroups](/patches/bartabgroups/) patch.

Showcase
--------

	Tile :
	+-----------------+--------+
	|                 |        |
	|                 |  S1    |
	|                 |        |
	|        M        +--------+
	|                 |        |
	|                 |   S2   |
	|                 |        |
	+-----------------+--------+

	Deck :
	+-----------------+--------+
	|                 |        |
	|                 |        |
	|                 |        |
	|        M        |   S1   |
	|                 |        |
	|                 |        |
	|                 |        |
	+-----------------+--------+

Download
--------
* [dwm-deck-6.0.diff](dwm-deck-6.0.diff)
* [dwm-deck-6.2.diff](dwm-deck-6.2.diff)
* [dwm-deck-rmaster-6.1.diff](dwm-deck-rmaster-6.1.diff)
* [dwm-deck-tilegap-6.1.diff](dwm-deck-tilegap-6.1.diff)
* [dwm-deck-double-6.2.diff](dwm-deck-double-6.2.diff)
* [dwm-deck-double-smartborders-6.2.diff](dwm-deck-double-smartborders-6.2.diff) : can be applied after [smartborders](/patches/smartborders/)

Author
------
* Jente Hidskes - `<jthidskes at outlook dot com>`
* Joshua Haase - `<hahj87 at gmail dot com>`
* Aleksandrs Stier
* Miles Alan - `<m at milesalan dot com>` (deck double patch)
* Jack Bird - `<jack.bird@dur.ac.uk>` (6.2 patch)
