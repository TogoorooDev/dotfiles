reorganizetags
==============

Description
-----------

Shifts all clients per tag to leftmost unoccupied tags.

For example, if clients A, B, C are tagged on tags 1, 5, 9 respectively, when
this function is called, they will now be on 1, 2, and 3. The focused client
will also remain focused.

Clients on multiple tags will be treated as if they only were only on their
leftmost tag, and will be reduced to one tag after the operation is complete.

Distribute Tags
---------------

This provides an additional feature to distribute the clients through
the tags as evenly as possible.

(The tags are filled left-to-right, looping back if necessary.)

Eg, if there are 9 clients and 9 tags then each tag will have one
client. If there are 19 clients, then 3 will be tagged onto tag 1, and
2 will be tagged onto each of tags 2 to 9.

Download
--------
* [dwm-reorganizetags-6.2.diff](dwm-reorganizetags-6.2.diff)
* [dwm-distributetags.h](dwm-distributetags.h)

Authors
-------
* Paul Baldaray - <paulbaldaray@gmail.com>
* kleinbottle4 - <kleinbottle4@gmail.com>
