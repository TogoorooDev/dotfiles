title parsing fix
=================

Description
-----------

Window titles in st get truncated after the first ';' character. I don't know
whether this is the expected behaviour but all terminals I have come across
do not truncate (for instance xterm, termite and alacritty). This patch "fixes"
that behaviour.

Download
--------
* [st-title\_parsing\_fix-0.8.4.diff](st-title_parsing_fix-0.8.4.diff)

Authors
-------
* Ashish Kumar Yadav - <ashishkumar.yadav@students.iiserpune.ac.in>
