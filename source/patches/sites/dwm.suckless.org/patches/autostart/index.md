autostart
=========

Description
-----------
This patch will make dwm run "~/.dwm/autostart\_blocking.sh" and
"~/.dwm/autostart.sh &" before entering the handler loop. One or both of these
files can be ommited.

Be aware that dwm will not startup as long as autostart\_blocking.sh is running
and will stay completely unresponsive. For obvious reasons it is generally a
bad idea to start X-applications here :)

Download
--------
* [dwm-autostart-20161205-bb3bd6f.diff](dwm-autostart-20161205-bb3bd6f.diff)
* [dwm-autostart-20210120-cb3f58a.diff](dwm-autostart-20210120-cb3f58a.diff)

  This patch modifies the dwm autostart feature to conform to the
  [XDG Base Directory specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html).

  The files listed above are looked up in the directories "$XDG\_DATA\_HOME/dwm",
  "$HOME/.local/share/dwm", and "$HOME/.dwm" respectively.  The first existing
  directory is used, no matter if it actually contains any file.

Authors
-------
* Pulled from: [https://github.com/axelGschaider/dwm-patch-autostart.sh/](https://github.com/axelGschaider/dwm-patch-autostart.sh/)
* Adapted to recent version Simon Bremer <simon.bremer@sys24.org>
* XDG Base Directory conformance additions Gan Ainm <gan.ainm.riomhphost@gmail.com>
