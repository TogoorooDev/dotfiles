w3m images
==========


Description
-----------
Support w3m images hack. Similar to the patch at the FAQ, but it's simpler,
smaller, and doesn't disable double-buffering in st.

Same as the FAQ patch, the cursor line is deleted at the image, because st
always renders full lines, even when most of it is empty.


Notes:
------
* The download is a `git --format-patch` file. It can be applied either with
  `git am ...`, or with `patch -p1 < ...`.


Download
--------
[st-w3m-0.8.3.diff](st-w3m-0.8.3.diff)


Author
------
* Avi Halachmi (:avih) - [https://github.com/avih](https://github.com/avih)
