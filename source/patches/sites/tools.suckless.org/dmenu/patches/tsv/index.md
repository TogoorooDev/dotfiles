tsv
====
With this patch dmenu will split input lines at first tab character and
only display first part, but it will perform matching on and output full
lines as usual.

This can be useful if you want to separate data and representation, for
example, a music player wrapper can display only a track title to
user, but still supply full filename to underlying script.

Download
--------
* [dmenu-tsv-20201101-1a13d04.diff](dmenu-tsv-20201101-1a13d04.diff)

Author
------
* Pavel Renev <an2qzavok@gmail.com>
