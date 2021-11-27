zoomswap
========

Description
-----------
This patch swaps the current window (C) with the previous master (P) when
zooming.

	Original behaviour :
	+-----------------+-------+
	|                 |       |
	|                 |       |
	|                 |       |
	|        P        +-------|
	|                 |       |
	|                 |   C   |
	|                 |       |
	+-----------------+-------+

	+-----------------+-------+
	|                 |       |
	|                 |   P   |
	|                 |       |
	|        C        +-------|
	|                 |       |
	|                 |       |
	|                 |       |
	+-----------------+-------+


	New Behaviour :
	+-----------------+-------+
	|                 |       |
	|                 |       |
	|                 |       |
	|        C        +-------+
	|                 |       |
	|                 |   P   |
	|                 |       |
	+-----------------+-------+

Download
--------
* [dwm-zoomswap-6.2.diff](dwm-zoomswap-6.2.diff)
* [dwm-zoomswap-20160731-56a31dc.diff](dwm-zoomswap-20160731-56a31dc.diff)
* [dwm-zoomswap-6.0.diff](dwm-zoomswap-6.0.diff) (1.6K) (20120406)

Author
------
* Jan Christoph Ebersbach - `<jceb at e-jc dot de>`
* Aleksandrs Stier (6.2)
