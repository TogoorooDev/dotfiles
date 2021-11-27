$NetBSD: patch-src_cmake_compiler.cmake,v 1.1 2021/01/19 16:02:25 nia Exp $

Disable custom rpath handling that conflicts with pkgsrc.

--- src/cmake/compiler.cmake.orig	2021-01-08 07:41:40.000000000 +0000
+++ src/cmake/compiler.cmake
@@ -542,32 +542,6 @@ endif ()
 
 
 ###########################################################################
-# Rpath handling at the install step
-#
-set (MACOSX_RPATH ON)
-if (CMAKE_SKIP_RPATH)
-    # We need to disallow the user from truly setting CMAKE_SKIP_RPATH, since
-    # we want to run the generated executables from the build tree in order to
-    # generate the manual page documentation.  However, we make sure the
-    # install rpath is unset so that the install tree is still free of rpaths
-    # for linux packaging purposes.
-    set (CMAKE_SKIP_RPATH FALSE)
-    unset (CMAKE_INSTALL_RPATH)
-else ()
-    if (NOT CMAKE_INSTALL_RPATH)
-        set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_FULL_LIBDIR}")
-    endif ()
-    # add the automatically determined parts of the RPATH that
-    # point to directories outside the build tree to the install RPATH
-    set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
-    if (VERBOSE)
-        message (STATUS "CMAKE_INSTALL_RPATH = ${CMAKE_INSTALL_RPATH}")
-    endif ()
-endif ()
-
-
-
-###########################################################################
 # Macro to install targets to the appropriate locations.  Use this instead
 # of the install(TARGETS ...) signature. Note that it adds it to the
 # export targets list for when we generate config files.
