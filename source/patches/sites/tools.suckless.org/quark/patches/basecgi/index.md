Base cgi support
================

Description
-----------
This patch adds basic cgi support for quark. It directly executes given script sending data via pipe in case of POST method and then reads script's stdout and sends it to client. This patch allows quark to accept any input data except for uploading files. Scripts are searched relatively to server root (-d option). This option is proceed before vhosts.

This patch is not tested on UDS.

Download
--------
* [quark-basecgi-20190317-4677877.diff](quark-basecgi-20190317-4677877.diff)

Author
------
* Platon Ryzhikov <ihummer63@yandex.ru>
