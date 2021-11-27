Digest auth
===========

Description
-----------
This patch adds support for Digest auth to quark. It follows RFC 7616, but
with some limitations:

* SHA-256 is unsupported, only MD5 can be used. If we lived in an ideal world,
  SHA-256 Digest auth would be supported by browsers since mid-2010s. Turns
  out that we aren't that lucky, so MD5 it is.
* Only auth qop mode is supported. If you want to protect the integrity of
  your connection, better use a TLS tunnel.

Download
--------
* [quark-digestauth-20201101-dff98c0.diff](quark-digestauth-20201101-dff98c0.diff)
* [quark-digestauth-20200916-5d0221d.diff](quark-digestauth-20200916-5d0221d.diff)

Author
------
* José Miguel Sánchez García <soy.jmi2k AT gmail DOT com>
