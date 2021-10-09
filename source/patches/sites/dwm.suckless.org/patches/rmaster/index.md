rmaster
=======

Description
-----------
Enables swapping the master- and stack area such that the master-client
appears on the right and the stack-clients appear on the left.

Configuration
-------------
A variable and a toggle-function are introduced to achieve this
behaviour which are set in the config.h:

* The rmaster-variable can be set to 1 to make the right area the
default master-area
* The togglemaster-function can be used to swap the master- and
stack-areas dynamically.

Download
--------
* [dwm-rmaster-6.1.diff](dwm-rmaster-6.1.diff) (20190418)
* [dwm-rmaster-6.2.diff](dwm-rmaster-6.2.diff) (20201116)

Author
------
* phi <crispyfrog@163.com>
* Aleksandrs Stier (Contributor)
* Peter Skrypalle (6.2 port)
