obey all sizehints
==================

Description
-----------
This patch makes dwm obey even "soft" sizehints for new clients. Any window
that requests a specific initial size will be floated and set to that size.
Unlike with "fixed size" windows, you are able to resize and/or unfloat these
windows freely - only the initial state is affected.

Ruled
-----
This version adds `isfreesize` rule to config which if set to 1 will enable  
the functionality of the patch. If rules for the given client aren't set in  
config dwm will set it to `1` and the client will benefit from `isfreesize`
rule if it has specific initial size requirements.  
`isfreesize` rule overrides `isfloating` rule in config.

Vanilla
-------
This version of the patch is honestly of limited utility since there are many  
clients that will abuse it.

There is no configuration for this version of the patch.

Download
--------
* [dwm-sizehints-isfreesize-6.2.diff](dwm-sizehints-isfreesize-6.2.diff) (20/06/2020)
* [dwm-sizehints-ruled-6.2.diff](dwm-sizehints-ruled-6.2.diff) (deprecated) (14/06/2020)
* [dwm-sizehints-6.2.diff](dwm-sizehints-6.2.diff) (12/06/2020)
* [dwm-sizehints-5.7.2.diff](dwm-sizehints-5.7.2.diff) (695B) (20091221)

Author
------
* MLquest8 (update for 6.2 and `Ruled` version) (miskuzius at gmail.com)
* Ray Kohler - ataraxia937 gmail com
