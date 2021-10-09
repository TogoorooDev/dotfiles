Print Index
==================
This patch allows dmenu to print out the 0-based index of matched text instead of the matched text itself.  This is useful in cases where you would like to select entries from one array of text but index into another, or when you are selecting from an ordered list of non-unique items.

Pass the _-ix_ flag to dmenu to enable index printing.

Download
--------
* [dmenu-printindex-5.0.diff](dmenu-printindex-5.0.diff)

Author
-------
* Jackson Abascal - <jacksonabascal@gmail.com>
