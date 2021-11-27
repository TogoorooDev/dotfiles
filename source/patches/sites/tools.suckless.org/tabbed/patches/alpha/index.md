Alpha
=====

Description
-----------
This patch create 32bit window in tabbed. This allows to handle windows with
transparency.

Note that *you need an X composite manager* (e.g. compton, xcompmgr) to make
this patch effective.

If you want to use transparency in st with this patch, you also need to replace

	#define USE_ARGB (alpha != OPAQUE && opt_embed == NULL)

by

	#define USE_ARGB (alpha != OPAQUE)

in st.c

Download
--------
* [alpha.diff](alpha.diff) (3.8k) (28 Feb 2017)

Author
------
* Sébastien Dailly - `<contact at chimrod dot com>`
