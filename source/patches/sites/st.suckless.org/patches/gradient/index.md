Gradient
========

Description
-----------
This patch adds an alpha gradient to st.
1.  It requires the alpha patch, i.e. apply it before applying this
2. Apply the patch to st's source code, and replace config.h with config.def.h before building the source
3. To customize, change the variables 'grad-alpha' and 'stat-alpha' in config.def.h
Maximum alpha value: minimum of grad-alpha + stat-alpha and 1
Minimum alpha value: minimum of stat-alpha and grad-alpha - 1
4. It is possible to invert the gradient by uncommenting the invert gradient code in x.c

Download
--------
* [st-gradient-0.8.4.diff](st-gradient-0.8.4.diff)

Author
------
* Sarthak Shah : shahsarthakw at gmail.com
