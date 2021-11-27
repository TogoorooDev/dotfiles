Space search
============

Description
-----------

This patch makes surf treat `_SURF_URI` string with leading whitespace as
search query. The search engine to send queries to is defined in `config.h`:

	static char *searchengine   = "https://duckduckgo.com/?q=";

(The patch adds this string to `config.def.h`.)

Download
--------

* [surf-0.6-spacesearch.diff](surf-0.6-spacesearch.diff) (701) (20131110)
* [surf-spacesearch-20170408-b814567.diff](surf-spacesearch-20170408-b814567.diff) (832) (20170408)

Author
------

* Dmitrij D. Czarkoff <czarkoff@gmail.com>
* Alexis Ben Miloud--Josselin; panpo; alexisbmj+code at protonmail dot com.
