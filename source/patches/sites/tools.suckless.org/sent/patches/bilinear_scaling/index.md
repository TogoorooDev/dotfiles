Use Bilinear Scaling for Image Slides
=====================================

Description
-----------
The patch replaces the Nearest Neighbor Scaling algorithm used for images with
Bilinear Scaling.

This should give somewhat more pleasing results when using image slides for
graphs, or other material which suffers badly under aliasing.

Notes
-----
Due to the nature of Bilinear Scaling, scaling down more than 50% will have
somewhat less pleasing results. Scaling up will generally be quite blurry.

There is room for further improvement of image scaling, e.g: Implementing a
better scaling algorithm such as bicubic, or lancszos; and/or using separate
algorithms for scaling up or down.

Download
--------
* [sent-bilinearscaling-1.0.diff](sent-bilinearscaling-1.0.diff)

Author
------
* Anton Kindestam (xantoz) <antonki@kth.se>
