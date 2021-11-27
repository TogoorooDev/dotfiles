spawn\_cwd
==========

Description
-----------
Spawns programs from currently focused client's working directory. See this
[blog post](https://sunaku.github.io/dwm-spawn-cwd-patch.html) for more information.

Currently the patch does not spawn into the cwd when the path
to the working directory is 15 characters of length. For example
spawning a new shell from a directory called ~/abcdefghijklm will
open the shell in the home directory instead. This happens because
the cwd to open is taken from the dwm status which gets truncated at a
certain depth using ellipses (.../path/to/long/dir/name).

Download
--------
* [dwm-6.0-spawn\_cwd.diff](dwm-6.0-spawn_cwd.diff)

Author
------
* Suraj N. Kurapati - <sunaku@gmail.com>
