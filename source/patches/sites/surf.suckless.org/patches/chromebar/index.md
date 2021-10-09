Chrome Bar
==========

Description
-----------

This patch is an extension of the [searchengines
patch](//surf.suckless.org/patches/searchengines).  It parses what you
type in the dmenu window when you input new address or a query.  If what you
wrote is not an internet address or a file`s uri, it will use a default search
engine to query for that phrase: like the chrome bar does.


Configuration
-------------

Add something like this to your `config.h`:

    static const char * defaultsearchengine = "http://www.google.co.uk/search?q=%s";
    static SearchEngine searchengines[] = {
	    { "g",   "http://www.google.de/search?q=%s"   },
	    { "leo", "http://dict.leo.org/ende?search=%s" },
    };

Download
--------

* [surf-0.1-chromebar.diff](surf-0.1-chromebar.diff) (20130703)

Author
------

* Marcin Szamotulski (coot) <mszamot@gmail.com>
