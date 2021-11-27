Community
=========

Mailing lists
-------------
* `dev@suckless.org` - for dwm/dmenu/st/... users, development discussion, bug
  reports and general discussion.
* `hackers@suckless.org` - **only for patches and upstream patch discussion**.
  Commit messages and diffs from all suckless projects are posted here and can be
  replied to.  [See patch/hacking guidelines here](//suckless.org/hacking).
  **DO NOT POST WIKI PATCHES OR BUG REPORTS HERE**.
  Please inline patches for easier review.
* `news@suckless.org` - for release and other news.  For admins: please send
  release news to dev@ too.
* `wiki@suckless.org` - for discussion about the wiki, also automatic wiki
  commit messages are posted here.

### Best practice

When beginning a new discussion on the mailing lists, except for the wiki@
mailing list, prepend your subject with the project name you are referring to.
This makes it easier for project maintainers to answer your questions.


Here is an example:

	Subject: [st] X not working

	When sending patches use the following form:

	Subject: [st][patch] subject here

In both cases describe the problem or the fix clearly.

* Don't use HTML mail: use plain-text UTF8.
* Don't top-post: bottom-post.

### Mailing list commands

Send a mail from your (not yet) subscribed email address to one of the
following addresses to perform the described action.

**After both the `subscribe` and `unsubscribe` command, a confirmation email will be sent to you (so look into your spam bin!)**

**Note, replace `MAILHOST` with `suckless.org`**

### `dev@suckless.org`

* `dev+subscribe@MAILHOST` - subscribe to the mailing list (read/write)
* `dev+subscribe-digest@MAILHOST` - subscribe to the digest version of the mailing list (read/write)
* `dev+subscribe-nomail@MAILHOST` - subscribe without receiving e-mails from the mailing list (write)
* `dev+unsubscribe@MAILHOST` - unsubscribe from the mailing list
* `dev+unsubscribe-digest@MAILHOST` - unsubscribe from the digest version
* `dev+unsubscribe-nomail@MAILHOST` - unsubscribe from the nomail version 
* `dev+get-N@MAILHOST` - retrieve message number N
* `dev+help@MAILHOST` - receive detailed description of the mailing list commands

### `hackers@suckless.org`

When sending a patch use the following commands:

	cd $project
	git send-email --subject-prefix="${PWD##*/}][PATCH" \
		--to hackers@suckless.org -1

This will send the last commit of the repository to the mailing list adding a
prefix to the subject which includes the appropriate project name. This allows
easier referencing and filtering of the e-mails for the maintainers subscribed
to hackers@.

Be sure to have setup your sender address in git and be subscribed to the
mailing list so you can see eventual comments on your patches.

* `hackers+subscribe@MAILHOST` - subscribe to the mailing list (read/write)
* `hackers+subscribe-digest@MAILHOST` - subscribe to the digest version of the mailing list (read/write)
* `hackers+subscribe-nomail@MAILHOST` - subscribe without receiving e-mails from the mailing list (write)
* `hackers+unsubscribe@MAILHOST` - unsubscribe from the mailing list
* `hackers+unsubscribe-digest@MAILHOST` - unsubscribe from the digest version
* `hackers+unsubscribe-nomail@MAILHOST` - unsubscribe from the nomail version 
* `hackers+get-N@MAILHOST` - retrieve message number N
* `hackers+help@MAILHOST` - receive detailed description of the mailing list commands

### `news@suckless.org`

* `news+subscribe@MAILHOST` - subscribe to the mailing list (read/write)
* `news+subscribe-digest@MAILHOST` - subscribe to the digest version of the mailing list (read/write)
* `news+subscribe-nomail@MAILHOST` - subscribe without receiving e-mails from the mailing list (write)
* `news+unsubscribe@MAILHOST` - unsubscribe from the mailing list
* `news+unsubscribe-digest@MAILHOST` - unsubscribe from the digest version
* `news+unsubscribe-nomail@MAILHOST` - unsubscribe from the nomail version 
* `news+get-N@MAILHOST` - retrieve message number N
* `news+help@MAILHOST` - receive detailed description of the mailing list commands

### `wiki@suckless.org`

* `wiki+subscribe@MAILHOST` - subscribe to the mailing list (read/write)
* `wiki+subscribe-digest@MAILHOST` - subscribe to the digest version of the mailing list (read/write)
* `wiki+subscribe-nomail@MAILHOST` - subscribe without receiving e-mails from the mailing list (write)
* `wiki+unsubscribe@MAILHOST` - unsubscribe from the mailing list
* `wiki+unsubscribe-digest@MAILHOST` - unsubscribe from the digest version
* `wiki+unsubscribe-nomail@MAILHOST` - unsubscribe from the nomail version 
* `wiki+get-N@MAILHOST` - retrieve message number N
* `wiki+help@MAILHOST` - receive detailed description of the mailing list commands

Mailing lists web archive
-------------------------
An archive of all mails posted to the mailing lists is accessible via
[lists.suckless.org](//lists.suckless.org/).

Related lists
-------------
* [9fans](http://plan9.bell-labs.com/wiki/plan9/mailing_lists/#9fans) - fans of
  the [Plan 9 from Bell Labs](http://9fans.net) operating system
* [inferno-list](http://plan9.bell-labs.com/wiki/plan9/mailing_lists/#INFERNO-LIST)
  - Inferno users and developers
* [9front](http://9front.org/) - 9front users and hackers
* [cat-v](http://cat-v.org/) - cat-v.org trolling

IRC
---
The channels are in the [OFTC](http://www.oftc.net) IRC network:
[irc.oftc.net](irc://irc.oftc.net/)

Official channel of suckless.org projects:

* [#suckless](irc://irc.oftc.net/#suckless)

Other popular channels:

* [#cat-v](irc://irc.freenode.net/#cat-v)
* [#plan9](irc://irc.freenode.net/#plan9)
* [#2f30](irc://irc.2f30.org/#2f30)
