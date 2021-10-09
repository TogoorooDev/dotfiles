Built-in downloading with console display
=========================================

Description
-----------

This patch removes the original downloading method of calling
an external tool and adds built-in support for downloads, along with
a simple console display with a list of downloads.

To open the downloads list, press Ctrl+D. This list must be manually
refreshed: simply press enter to do so. If you enter `clean` as a command,
the list will be cleared. The shell command called to show the downloads
is defined by the macro `DLSTATUS` in the `config.def.h` file.

Download
--------

* [surf-dlconsole-20190919-d068a38.diff](surf-dlconsole-20190919-d068a38.diff) (20190919)

Author
------

* danoloan10 <danoloan10@tutanota.com>
