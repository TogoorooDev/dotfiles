externalpipe
============

Description
-----------
Reading and writing st's screen through a pipe.

Example
-------
config.h example, binding `TERMMOD + U` to extract all visible URLs and present
dmenu to select and open one:

	static char *openurlcmd[] = { "/bin/sh", "-c",
		"xurls | dmenu -l 10 -w $WINDOWID | xargs -r open",
		"externalpipe", NULL };
	Shortcut shortcuts[] = {
		...
		{ TERMMOD, XK_U, externalpipe, { .v = openurlcmd } },
	};

([xurls](https://raw.github.com/bobrippling/perlbin/master/xurls) and
[open](https://github.com/bobrippling/open) are external scripts)

### Example Shell Scripts

* [link grabber](linkgrabber.sh) - similar to the function above, but without
  xurls dependency
* [edit screen](editscreen.sh) - open screen in `$EDITOR`  for copying text

Download
--------
* [st-externalpipe-0.4.1.diff](st-externalpipe-0.4.1.diff)
* [st-externalpipe-0.5.diff](st-externalpipe-0.5.diff)
* [st-externalpipe-0.6.diff](st-externalpipe-0.6.diff)
* [st-externalpipe-0.7.diff](st-externalpipe-0.7.diff)
* [st-externalpipe-20170608-b331da5.diff](st-externalpipe-20170608-b331da5.diff)
* [st-externalpipe-0.8.diff](st-externalpipe-0.8.diff)
* [st-externalpipe-0.8.1.diff](st-externalpipe-0.8.1.diff)
* [st-externalpipe-20181016-3be4cf1.diff](st-externalpipe-20181016-3be4cf1.diff)
* [st-externalpipe-0.8.2.diff](st-externalpipe-0.8.2.diff)
* [st-externalpipe-0.8.4.diff](st-externalpipe-0.8.4.diff)

When using the scrollback patch, you can apply this patch ontop in order to use
externalpipe onto the entire terminal history:

* [st-externalpipe-eternal-0.8.3.diff](st-externalpipe-eternal-0.8.3.diff)

Authors
-------
* Rob Pilling - <robpilling@gmail.com> (original, 0.8, git ports)
* Laslo Hunhold - <dev@frign.de> (0.4.1, 0.5, 0.6, git ports)
* Lucas Gabriel Vuotto - <lvuotto92@gmail.com> (0.7, git ports)
