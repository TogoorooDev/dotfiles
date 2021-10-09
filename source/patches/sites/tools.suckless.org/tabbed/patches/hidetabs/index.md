Hide Tabs
=========

Description
-----------
This patch hides all the tabs and only shows them when Mod+Shift is pressed.
All functions with switching, rotating, and creating tabs involve Mod+Shift.
When not doing one of these functions, visibility of the tabs is not needed.

This patch relies on the keyrelease patch to support show/hide on 
keypress/keyrelease.

This patch was inspired by and borrows from the autohide patch originally 
by Carlos Pita.

Download
--------
* [tabbed-hidetabs-20191216-b5f9ec6.diff](tabbed-hidetabs-20191216-b5f9ec6.diff)

Author
------
* Leela Pakanati - <leela.pakanati@gmail.com>
