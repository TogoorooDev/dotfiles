Customisation
=============
**dwm** is customised by editing **config.h**, a C language header file, and
**config.mk**, a Make include file.

What is config.h?
-----------------
config.h is a source code file which is included by dwm.c, the main dwm source
code module. It serves as the configuration file for all of dwm's features,
e.g., application placement, tags, and colours. A vanilla download of dwm will
contain a file called config.def.h, a template you can use to create your own
config.h file. To start customising dwm, simply copy config.def.h into config.h
before you run make.

What is config.mk?
------------------
config.mk is a file included by Makefile. It allows you to configure how make
is going to compile and install dwm.

How do I modify config.h?
-------------------------
config.h can be edited just like any other C source code file. It contains
definitions of variables that are going to be used by dwm.c and therefore it is
vital that the file is always up to date. The default Makefile distributed with
dwm will not overwrite your customised config.h with the contents of
config.def.h, even if it was updated in the latest git pull. Therefore, you
should always compare your customised config.h with config.def.h and make sure
you include any changes to the latter in your config.h.

How do I modify **config.mk**?
------------------------------
config.mk can be edited just like any other text file. It contains definitions
of variables that are going to be used inside Makefile. Unlike config.h,
config.mk does not have a config.def.mk (a default Makefile). Therefore, during
an update of your repository you may run into conflicts if the original
config.mk is edited.

Are there any example customisations to get me started?
-------------------------------------------------------
Various customisation options are illustrated in the sub-directories of this
wiki page. Under each of the categories (customfuncs, fonts, etc.,) you will
find example modifications that will get you started.
