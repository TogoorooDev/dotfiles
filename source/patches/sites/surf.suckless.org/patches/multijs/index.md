MultiJS
=======

Description
-----------
This patch replaces scriptfile with an array of scriptfiles[]. This allows for
the inclusion of multiple javascript files instead of filling up one file with
multiple script plugins.

Javascript files can be included in `config.def.h`:

static char *scriptfiles[] = {
	"path/to/script1.js",
	"path/to/script2.js",
};

Download
--------
* [surf-multijs-20190325-d068a38.diff](surf-multijs-20190325-d068a38.diff)

Author
------
* knary <mailto:theknary@gmail.com>
