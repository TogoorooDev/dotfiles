wmname
======
wmname prints/sets the window manager name property of the root window similar
to how hostname(1) behaves.

wmname is a nice utility to fix problems with JDK versions and other broken
programs assuming a reparenting window manager for instance.

Download
--------
* [wmname-0.1](//dl.suckless.org/tools/wmname-0.1.tar.gz)

Repository
----------
You can [browse](//git.suckless.org/wmname) the source code or get a copy using
the following command:

	git clone https://git.suckless.org/wmname

Usage
-----
The following command prints the window manager name, if any:

	$ wmname

This is helpful when attempting to run java swing(broken) applications,
it makes them think they are running through the looking glass and behave as
expected. The following command sets the window manager name, e.g.

	$ wmname LG3D

