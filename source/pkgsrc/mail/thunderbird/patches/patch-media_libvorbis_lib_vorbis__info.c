$NetBSD: patch-media_libvorbis_lib_vorbis__info.c,v 1.1 2020/09/03 15:26:22 ryoon Exp $

--- media/libvorbis/lib/vorbis_info.c.orig	2020-08-28 21:33:11.000000000 +0000
+++ media/libvorbis/lib/vorbis_info.c
@@ -78,7 +78,7 @@ void vorbis_comment_add_tag(vorbis_comme
 static int tagcompare(const char *s1, const char *s2, int n){
   int c=0;
   while(c < n){
-    if(toupper(s1[c]) != toupper(s2[c]))
+    if(toupper((unsigned char) s1[c]) != toupper((unsigned char) s2[c]))
       return !0;
     c++;
   }
