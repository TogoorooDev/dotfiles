attachaside
===========

Description
-----------
Make new clients get attached and focused in the stacking area instead of
always becoming the new master. It's basically an
[attachabove](../attachabove/) modification.

	Original behaviour :
	+-----------------+-------+
	|                 |       |
	|                 |   P   |
	|                 |       |
	|        N        +-------+
	|                 |       |
	|                 |       |
	|                 |       |
	+-----------------+-------+


	New Behaviour :
	+-----------------+-------+
	|                 |       |
	|                 |   N   |
	|                 |       |
	|        P        +-------+
	|                 |       |
	|                 |       |
	|                 |       |
	+-----------------+-------+


	+-----------------+-------+
	|                 |       |
	|                 |   P   |
	|                 |       |
	|                 +-------+
	|                 |       |
	|                 |   N   |
	|                 |       |
	+-----------------+-------+

Download
--------
* [dwm-attachaside-6.1.diff](dwm-attachaside-6.1.diff)
* [dwm-attachaside-20160718-56a31dc.diff](dwm-attachaside-20160718-56a31dc.diff)
* [dwm-attachaside-20180126-db22360.diff](dwm-attachaside-20180126-db22360.diff)


Authors
-------
* Jerome Andrieux - <jerome@gcu.info>
* Chris Down - <chris@chrisdown.name> (6.1 port and fixes)
* Laslo Hunhold - <dev@frign.de> (git port)
