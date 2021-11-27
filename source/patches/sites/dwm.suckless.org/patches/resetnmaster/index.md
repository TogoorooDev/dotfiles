resetnmaster
============

Description
-----------
Set the number of clients in master area to 1.
This is so tiny it doesn't deserve a full diff.

Configuration
-------------
Add the `resetnmaster` declaration before keys array in your config.h : 

    void resetnmaster(const Arg *arg);

Add the following line to the keys array in your config.h (or config.def.h) to bind Mod+o
to resetnmaster.

	{ MODKEY,           XK_o,  resetnmaster,    {0} },

Add at the end of you config.h:

	void
	resetnmaster(const Arg *arg)
	{
		selmon->nmaster = 1;
		arrange(selmon);
	}


Author
------
* prx <prx at si3t dot ch>
