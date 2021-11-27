URL filtering
=============

Description
-----------

This patch adds URL filtering support to surf, for example to remove
advertisements. The file `filters` contains POSIX regular expressions (see the
`re_format(7)` manpage). If a HTTP request is about to be made for a URL that
matches any of the expressions in the file, it is replaced with `about:blank`
instead. This may lead to slightly broken display on pages that expect e.g.
images to load correctly. The impact is negligible though.

Example
-------

An example list of filters looks like this:

	/favicon\.ico$
	eviladvertismentcompany\.{net,com}/ads

Download
--------

* [surf-tip-url-filtering.diff](surf-tip-url-filtering.diff) (4176) (20141014)
