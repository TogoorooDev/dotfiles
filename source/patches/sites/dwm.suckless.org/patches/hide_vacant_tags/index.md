hide vacant tags
================

Description
-----------
This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the
bar.

It also makes sure that pressing a tag on the bar behaves accordingly by not
reserving reactive regions on the bar for vacant tags.

It also stops drawing empty rectangles on the bar for non-vacant tags as there
is no need anymore to distinguish vacant tags and it offers a more visible
contrast than if there were filled/empty rectangles.

Download
--------
* [dwm-hide\_vacant\_tags-6.1.diff](dwm-hide_vacant_tags-6.1.diff) - 2016-01-22
* [dwm-hide\_vacant\_tags-git-20160626-7af4d43.diff](dwm-hide_vacant_tags-git-20160626-7af4d43.diff)
* [dwm-hide\_vacant\_tags-6.2.diff](dwm-hide_vacant_tags-6.2.diff)

Author
------
* [Ondřej Grover](mailto:ondrej.grover@gmail.com)
* Matthew Boswell - mordervomubel+suckless at lockmail dot us (mechanical update for dwm 6.1 release)
* [Jochen Sprickerhof](mailto:project@firstname.lastname.de) (hide 0 tagged clients)
