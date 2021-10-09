Do not require root privileges
==============================

Description
-----------
This patch removes the necessity and ability to run quark as root. quark
will neither chroot(2) into the serving directory nor change the UID,
GID or ownership of the UNIX-domain socket file.

As this patch removes security features from quark, it should not be
used for serving content to untrusted parties.

This patch has not been tested with a UNIX-domain socket file.

Download
--------
* [quark-noroot-20191003-3c7049e.diff](quark-noroot-20191003-3c7049e.diff)

Author
------
* Richard Ulmer <codesoap AT mailbox DOT org>
