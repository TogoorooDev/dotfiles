Usernames
=========

Description
-----------
Changes the handling of QUIT and NICK messages from other users so that the
output is written to the relevant channels rather than the server output. This
patch is rather bulky but it gets the job done.

Notes
-----
I have tested this patch against the other patches posted here and they all
apply, but for some of them you must apply this patch first or there will be
conflicts.

Download
--------
* [ii-1.4-usernames.diff](ii-1.4-usernames.diff)
* [ii-1.8-usernames.diff](ii-1.8-usernames.diff)

Author
------
* Robert Lowry (bobertlo) <robertwlowry@gmail.com>
* Ported to 1.8 by hicsfield
