OSC 10, 11, 12 #2
-----------------

Description
-----------

This patch adds support for OSC 10, 11, and 12 in the way they are implemented
in most other terminals (e.g libvte, kitty). Specifically it differs from
osc_10_11_12 in that it treats the background and foreground colors as distinct
from palette colours 01 and 07 in order to facilitate the use of theme setting
scripts like [theme.sh](https://github.com/lemnos/theme.sh) which expect these
colours to be distinct.


Download
--------
* [st-osc10-20210106-4ef0cbd.diff](st-osc10-20210106-4ef0cbd.diff)

Authors
-------
* Raheman Vaiya - <r.vaiya at gmail dot com>
