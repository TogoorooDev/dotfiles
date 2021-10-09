Edit source
===========

Description
-----------

This script named say editurl allows the user to edit the source of the current page without fetching the page again
in three keystrokes:

	#!/bin/sh  
	dir=~/.surf/tmpedit  
	name=`ls $dir | wc -l`  
	file=$dir/$name.html  
	sselp > $file && urxvtc -e vi $file  

To launch it, you can add the following in config.h above the line "static Key keys[] = {" :

	#define EDIT             { .v = (char *[]){ "/bin/sh", "-c", "editurl", NULL } }

and the following in the "static Key keys[] = {" part  

	{ MODKEY,               GDK_e,      spawn,      EDIT },

The three required keystrokes are :  
* modkey o  
* modkey a  
* modkey e  


Author
------

- Julien Steinhauser <julien.steinhauser@orange.fr>
