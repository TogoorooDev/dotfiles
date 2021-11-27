stackmfact
==========

Description
-----------
`stackmfact` enables you to vertically resize clients in the stack, like the
regular mfact enables you to horizontally resize the master client(s).


	smfact 0.00 (original behaviour):
	+-----------------+-------+
	|                 |       |
	|                 |  S1   |
	|                 |       |
	|        M        +=======|
	|                 |       |
	|                 |  S2   |
	|                 |       |
	+-----------------+-------+


	smfact > 0.00 (new behaviour):
	+-----------------+-------+
	|                 |  S1   |
	|                 +=======+
	|                 |       |
	|        M        |       |
	|                 |       |
	|                 |  S2   |
	|                 |       |
	+-----------------+-------+

Download
--------
* [dwm-6.0-smfact.diff](dwm-6.0-smfact.diff)

Author
------
* Jente Hidskes - `<jthidskes at outlook dot com>`
