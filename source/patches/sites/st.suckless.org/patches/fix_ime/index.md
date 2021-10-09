Fix IME
=======

This patch is now applied in st master e85b6b6 right after release 0.8.2.

Description
-----------
Better Input Method Editor (IME) support. Features:

* Allow input methods swap with hotkey (E.g. left ctrl + left shift)
* Over-the-spot pre-editing style, pre-edit data placed over insertion point
* Restart IME without segmentation fault

TODO:

* Automatically pickup IME if st started before IME

Download
--------
* [st-ime-20190202-3be4cf1.diff](st-ime-20190202-3be4cf1.diff)

Authors
-------
* Ivan Tham - <pickfire@riseup.net>
