$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.1 2020/09/03 20:22:26 ryoon Exp $

--- toolkit/components/terminator/nsTerminator.cpp.orig	2019-09-09 23:43:45.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -36,7 +36,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -170,7 +170,10 @@ void RunWatchdog(void* arg) {
 #if defined(XP_WIN)
     Sleep(1000 /* ms */);
 #else
-    usleep(1000000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = 1;
+    tickd.tv_nsec = 0;
+    nanosleep(&tickd, NULL);
 #endif
 
     if (gHeartbeat++ < timeToLive) {
