$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.1 2020/09/03 20:22:26 ryoon Exp $

--- toolkit/mozapps/installer/packager.mk.orig	2019-09-09 23:43:44.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -138,7 +138,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) $(UPLOAD_FILES)
