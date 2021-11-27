Joinuser
========

Description
-----------
By default to PRIVMSG a user you need to `/j user message`, this patch makes
`message` optional. It also displays "-!- yournick has joined user" prior to
any messages both when you `/j user` and when a user messages you, and
incorporates the [autojoin](//tools.suckless.org/ii/patches/autojoin) patch, so
you do not need to `/j user` first to talk to someone who has already messaged
you.

Download
--------
* [ii-1.4-joinuser.diff](ii-1.4-joinuser.diff)

Author
------
* Robert Lowry (bobertlo) <robertwlowry@gmail.com>
* Evan Gates (emg) <evan.gates@gmail.com>
