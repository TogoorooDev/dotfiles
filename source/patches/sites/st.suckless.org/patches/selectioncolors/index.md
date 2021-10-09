selectioncolors
===============

Description
-----------

This patch adds the two color-settings *selectionfg* and *selectionbg* to
config.def.h. Those define the fore- and background colors which are used when
text on the screen is selected with the mouse. This removes the default
behaviour which would simply reverse the colors.

Additionally, a third setting *ingnoreselfg* exists. If true then the setting
*selectionfg* is ignored and the original foreground-colors of each cell are
not changed during selection. Basically only the background-color would change.
This might be more visually appealing to some folks.

Download
--------
* [st-selectioncolors-0.8.4.diff](st-selectioncolors-0.8.4.diff)
* [st-selectioncolors-0.8.2.diff](st-selectioncolors-0.8.2.diff)

Authors
-------
* Aleksandrs Stier (0.8.2)
* Ashish Kumar Yadav - <ashishkumar.yadav@students.iiserpune.ac.in> (0.8.4,
  don't disable color reversing for external programs)
