keychain
========

Description
-----------
This patch modifies the key handing so that you can chain multiple bindings
together like in sxhkd. After pressing Mod + ChainKey the next key press
will be matched against any KEY in the keys array which is part of the Mod +
ChainKey group and execute its function. If there isn't any match the key press
will be consumed without any effect. This allows you group certain bindings
together which all starts with the specified Mod + ChainKey prefix.

Download
--------
* [dwm-keychain-20200729-053e3a2.diff](dwm-keychain-20200729-053e3a2.diff)

Author
------
* [Stefan Matz (braunbearded)](mailto:braunbearded1@gmail.com)
