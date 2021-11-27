$NetBSD: patch-sope-core_NGStreams_NGInternetSocketAddress.m,v 1.1 2019/09/11 11:32:26 tm Exp $

Add support for DragonFly.

--- sope-core/NGStreams/NGInternetSocketAddress.m.orig	2012-11-15 18:51:03.000000000 +0100
+++ sope-core/NGStreams/NGInternetSocketAddress.m	2012-11-22 18:39:01.000000000 +0100
@@ -47,9 +47,9 @@
 #include "NGInternetSocketAddress.h"
 #include "NGInternetSocketDomain.h"
 #include "common.h"

-#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__) && !defined(__GLIBC__)
+#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__) && !defined(__GLIBC__) && !defined(__DragonFly__)
 #define USE_GETHOSTBYNAME_R 1
 #endif

 @implementation NGInternetSocketAddress
