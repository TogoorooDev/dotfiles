$NetBSD: patch-gfx_skia_skia_src_core_SkCpu.cpp,v 1.2 2020/09/03 15:26:22 ryoon Exp $

--- gfx/skia/skia/src/core/SkCpu.cpp.orig	2020-08-28 21:32:36.000000000 +0000
+++ gfx/skia/skia/src/core/SkCpu.cpp
@@ -72,7 +72,7 @@
         return features;
     }
 
-#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
+#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>) && !defined(__NetBSD__)
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
