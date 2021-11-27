$NetBSD: patch-encoding.c,v 1.1 2021/03/13 07:24:04 kim Exp $

https://salsa.debian.org/debian/screen/-/raw/master/debian/patches/99_CVE-2021-26937.patch

Description: [CVE-2021-26937] Fix out of bounds array access
Author: Michael Schröder <mls@suse.de>
Bug-Debian: https://bugs.debian.org/982435
Bug: https://savannah.gnu.org/bugs/?60030
Bug: https://lists.gnu.org/archive/html/screen-devel/2021-02/msg00000.html
Bug-OSS-Security: https://www.openwall.com/lists/oss-security/2021/02/09/3
Origin: https://lists.gnu.org/archive/html/screen-devel/2021-02/msg00010.html

--- encoding.c.orig
+++ encoding.c
@@ -43,7 +43,7 @@
 # ifdef UTF8
 static int   recode_char __P((int, int, int));
 static int   recode_char_to_encoding __P((int, int));
-static void  comb_tofront __P((int, int));
+static void  comb_tofront __P((int));
 #  ifdef DW_CHARS
 static int   recode_char_dw __P((int, int *, int, int));
 static int   recode_char_dw_to_encoding __P((int, int *, int));
@@ -1263,6 +1263,8 @@
     {0x30000, 0x3FFFD},
   };
 
+  if (c >= 0xdf00 && c <= 0xdfff)
+    return 1;          /* dw combining sequence */
   return ((bisearch(c, wide, sizeof(wide) / sizeof(struct interval) - 1)) ||
           (cjkwidth &&
            bisearch(c, ambiguous,
@@ -1330,11 +1332,12 @@
 }
 
 static void
-comb_tofront(root, i)
-int root, i;
+comb_tofront(i)
+int i;
 {
   for (;;)
     {
+      int root = i >= 0x700 ? 0x801 : 0x800;
       debug1("bring to front: %x\n", i);
       combchars[combchars[i]->prev]->next = combchars[i]->next;
       combchars[combchars[i]->next]->prev = combchars[i]->prev;
@@ -1396,9 +1399,9 @@
     {
       /* full, recycle old entry */
       if (c1 >= 0xd800 && c1 < 0xe000)
-        comb_tofront(root, c1 - 0xd800);
+        comb_tofront(c1 - 0xd800);
       i = combchars[root]->prev;
-      if (c1 == i + 0xd800)
+      if (i == 0x800 || i == 0x801 || c1 == i + 0xd800)
 	{
 	  /* completely full, can't recycle */
 	  debug("utf8_handle_comp: completely full!\n");
@@ -1422,7 +1425,7 @@
   mc->font  = (i >> 8) + 0xd8;
   mc->fontx = 0;
   debug3("combinig char %x %x -> %x\n", c1, c, i + 0xd800);
-  comb_tofront(root, i);
+  comb_tofront(i);
 }
 
 #else /* !UTF8 */