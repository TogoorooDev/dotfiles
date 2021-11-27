json
=======
Adds support for json-files. Only use object and strings.

Requires [jansson](http://www.digip.org/jansson/)

`dmenu -j ~/.bookmarks`

Usefull code for surf:
   #define BOOKMARKS(u, p) { \
           .v = (const char *[]){ "/bin/sh", "-c", \
                   "prop=$(dmenu -p \"$3\" -w $1 -j ~/.bookmarks) && " \
                   "xprop -id $1 -f $2 8s -set $2 \"$prop\"", \
                   "surf-bookmark", winid, u, p, NULL \
           } \
   }
   
   { MODKEY,                GDK_KEY_b,      spawn,      BOOKMARKS("_SURF_GO", PROMPT_GO) },


Download
--------
* [dmenu-json-4.9-r2.diff](dmenu-json-4.9-r2.diff)

Author
------
* C.J.Wagenius <cjw@voidptr.se>
