$NetBSD: patch-site__scons_site__tools_libtool.py,v 1.1 2019/03/05 19:35:58 adam Exp $

Use system libtool (Darwin only).

--- site_scons/site_tools/libtool.py.orig	2019-03-04 18:25:28.000000000 +0000
+++ site_scons/site_tools/libtool.py
@@ -2,7 +2,7 @@ import SCons
 
 def generate(env):
 
-    env['AR'] = 'libtool'
+    env['AR'] = '/usr/bin/libtool'
     env['ARCOM'] = '$AR -static -o $TARGET $ARFLAGS $SOURCES'
     env['ARFLAGS'] = ["-s", "-no_warning_for_no_symbols"]
 
