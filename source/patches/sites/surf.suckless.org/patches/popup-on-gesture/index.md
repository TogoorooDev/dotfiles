Allow popup on gesture
========================

Description
-----------

Enable same-window popup on user gesture. 
(some pages don't work correctly without that, others redirect to spam pages though)

To open popup in new window open diff file and replace:

+   loaduri((Client *) c, &aa);

with:

+   newwindow(c, &aa, 1);

Download
--------

* [surf-popup-2.0.diff](surf-popup-2.0.diff) (1037) (20171203)

Author
------

* Marcin sZpak <szpak@reakcja.org>
