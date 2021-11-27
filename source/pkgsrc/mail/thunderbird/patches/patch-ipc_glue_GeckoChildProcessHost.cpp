$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.10 2020/09/03 15:26:22 ryoon Exp $

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2020-08-28 21:32:41.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/string_util.h"
