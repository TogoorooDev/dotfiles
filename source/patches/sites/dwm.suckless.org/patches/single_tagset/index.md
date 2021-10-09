single tagset
=============

Description
-----------
This patch addresses the multi-monitor setup. Instead of having separate tags
for every monitor there is just one list of tags for all monitors. Instead of
moving windows from one monitor to the other, the desired tag from the other
monitor can just be selected and all windows will be drawn on the current
monitor.

Several deep changes needed to be made:
1. Macro ISVISIBLE expects a second parameter, the monitor
2. Monitor->clients and Monitor->stack were moved to the global variable
   Clientlist cl. All monitors refer to this one list.
3. A new method attachclients was added. When changing between tags this
   function ensures that all clients are pointing to the right monitor.

Download
--------
* [dwm-single\_tagset-20210623-67d76bd.diff](dwm-single_tagset-20210623-67d76bd.diff)
* [dwm-single\_tagset-6.2.diff](dwm-single_tagset-6.2.diff)
* [dwm-single\_tagset-20160731-56a31dc.diff](dwm-single_tagset-20160731-56a31dc.diff)
* [dwm-6.1-single\_tagset.diff](dwm-6.1-single_tagset.diff) (16634b) (20140209)
* [dwm-single\_tagset-6.0.diff](dwm-single_tagset-6.0.diff) (14417b) (20120406)

Authors
-------
* Jan Christoph Ebersbach - <jceb@e-jc.de>
* Mohammad Zeinali - <mzeinali@tutanota.com>
* Jesus Mastache Caballero - <BrunoCooper17@outlook.com>
