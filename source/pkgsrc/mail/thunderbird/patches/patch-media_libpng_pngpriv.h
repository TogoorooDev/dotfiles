$NetBSD: patch-media_libpng_pngpriv.h,v 1.2 2020/09/03 15:26:22 ryoon Exp $

--- media/libpng/pngpriv.h.orig	2020-08-28 21:33:11.000000000 +0000
+++ media/libpng/pngpriv.h
@@ -36,8 +36,10 @@
  * still required (as of 2011-05-02.)
  */
 #ifndef _POSIX_SOURCE
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 # define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
 #endif
+#endif
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
