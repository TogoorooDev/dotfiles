$NetBSD: patch-ghc.mk,v 1.2 2021/05/01 03:00:07 pho Exp $

Use the wrapper scripts for ghc as we can't use the ones from the DESTDIR
as the libraries are not in the right place yet.

--- ghc.mk.orig	2020-07-08 16:43:03.000000000 +0000
+++ ghc.mk
@@ -959,7 +959,7 @@ endif
 
 INSTALLED_PACKAGE_CONF=$(DESTDIR)$(topdir)/package.conf.d
 
-ifeq "$(BINDIST) $(CrossCompiling)" "NO YES"
+ifeq "$(BINDIST)" "NO"
 # when installing ghc-stage2 we can't run target's
 # 'ghc-pkg' and 'ghc-stage2' but those are needed for registration.
 INSTALLED_GHC_REAL=$(TOP)/inplace/bin/ghc-stage1
