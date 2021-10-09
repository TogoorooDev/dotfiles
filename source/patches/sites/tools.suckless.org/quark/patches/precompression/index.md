precompression
==============

Description
-----------

This patch adds a new capability to serve compressed versions of requested files.

If the client supports compression, quark will try to serve <file>.gz first, if it exists.

This method is cheap to implement, but has several shortcomings:
* Dirlists are not supported
* Range requests are not supported

You can generate compressed files for your webroot using
	find /var/www -type f -exec gzip -k {} \;

Download
--------
* [quark-precompression-20200308-3c7049e.diff](quark-precompression-20200308-3c7049e.diff) 
