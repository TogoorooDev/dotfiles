Change font in config.h
=======================
Towards the beginning of **config.h**, you will find a line defining the
variable

	static const char font[] = "..."

By using **xfontsel**, you can produce a font line for the font you would like
to be used by **dwm** when displaying text in the menubar.

For example, to change the font to 'fixed', you can change the value of font
to:

	static const char font[] = "-misc-fixed-medium-r-semicondensed--13-100-100-100-c-60-iso8859-1";

The following patch also produces the same result:

	--- a/config.def.h      Mon Jul 28 20:23:16 2008 +0100
	+++ b/config.def.h      Mon Jul 28 20:45:27 2008 +0100
	@@ -1,7 +1,7 @@
	 /* See LICENSE file for copyright and license details. */
	
	 /* appearance */
	-static const char font[]            = "-*-terminus-medium-r-normal-*-14-*-*-*-*-*-*-*";
	+static const char font[]            = "-misc-fixed-medium-r-semicondensed--13-100-100-100-c-60-iso8859-1";
	 static const char normbordercolor[] = "#cccccc";
	 static const char normbgcolor[]     = "#cccccc";
	 static const char normfgcolor[]     = "#000000";
