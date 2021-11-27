prefix completion
=================

Description
-----------
Changes the behaviour of the matched items and the Tab key.

* Only items prefixed by the written text will match. E.g. query "foo" will
  match "foo", "foobar" and "fool", but not "world" or "barfoo".
* The Tab key will replace the current query with the longest common prefix of
  all matches. E.g. completing "f" with matches "foobar" and "fool" will become
  "foo".

The `-flag` variant adds a `use_prefix` setting and `-x` flag; useful if you
only want some instances of dmenu to do prefix matching.

Download
--------
* For 4.6: [dmenu-prefixcompletion-4.6.diff](dmenu-prefixcompletion-4.6.diff)
* For 4.7: [dmenu-prefixcompletion-4.7.diff](dmenu-prefixcompletion-4.7.diff)
* For 4.8: [dmenu-prefixcompletion-4.8.diff](dmenu-prefixcompletion-4.8.diff)
* For 4.9: [dmenu-prefixcompletion-4.8.diff](dmenu-prefixcompletion-4.9.diff)

* [dmenu-prefixcompletion-flag-4.9.diff](dmenu-prefixcompletion-flag-4.9.diff)

Authors
-------

* ninewise
* Martin Tournoij <martin@arp242.net> – `-x` patch.
