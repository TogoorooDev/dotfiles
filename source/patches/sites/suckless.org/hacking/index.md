Hacking
=======

Copying/license
---------------
We only accept contributions from individuals, not corporate entities. See the
project LICENSE file you're contributing to.

Debugging
---------
If you find any crashes, please send a full backtrace to the dedicated mailing
list. You can create backtraces with `gdb`:

Before starting a program, you may have to allow core file creation. It is
recommended that you put this in your profile:

	$ ulimit -c unlimited

Then start the program as usual.

After the program crashes, do the following:

	$ gdb -q `which program` /path/to/core
	gdb> bt full

If you encounter freezes (no crash at all) of the program, you can debug as
follows:

	$ gdb -q `which program` --attach `pgrep -o  program`
	gdb> bt full

Send the output of that command to the mailing list along with the output of
`program -v`! Thank you!

Patches
-------
There are two types of patches: The ones that fit to your personal taste and
the ones you think should be included in mainline.

For patches that fit your personal taste and you want to share with the
community, please follow the instructions on the [wiki](//suckless.org/wiki)
page on how to edit the pages you see here.

For patches that should be included in mainline see the
[community](//suckless.org/community) page and the hackers@ mailing list.
Please note that only patches to be included in mainline repos are to be
submitted to this list, customisation patches are to be submitted to the wiki!

Please provide a clear concise "commit message" for your patches.

The following instructions are a general guide on how to generate and apply
patches posted on this wiki:

patch filename format
---------------------
The expected format for patches is:

For git revisions:

	toolname-patchname-YYYYMMDD-SHORTHASH.diff
	dwm-allyourbase-20160617-3465bed.diff

The YYYYMMDD date should correspond to the last time the patch has been
modified. The SHORTHASH here is the seven chars git commit short hash
corresponding to the last commit of the tool on which the patch can be applied
correctly and is working with. You can get it by taking the first seven chars
of the full hash or for example:

	git rev-parse --short <commit-id> (with commit-id: HEAD, commit hash, etc.)

For release versions:

	toolname-patchname-RELEASE.diff
	dwm-allyourbase-6.1.diff

The RELEASE should correspond to the tool release version, ie 6.1 for dwm-6.1.

diff generation
---------------
For git users:

	cd program-directory
	git add filechanges...
	git commit (write a clear patch description)
	git format-patch --stdout HEAD^ > toolname-patchname-YYYYMMDD-SHORTHASH.diff

For tarballs:

	cd modified-program-directory/..
	diff -up original-program-directory modified-program-directory > \
	           toolname-patchname-RELEASE.diff

Don't push multiple commits patchsets. A single patch should apply all changes
using `patch -p1`.

patch program
-------------
For git users, use -3 to fix the conflict easily:

	cd program-directory
	git apply path/to/patch.diff

For patches formatted with git format-patch:

	cd program-directory
	git am path/to/patch.diff

For tarballs:

	cd program-directory
	patch -p1 < path/to/patch.diff
