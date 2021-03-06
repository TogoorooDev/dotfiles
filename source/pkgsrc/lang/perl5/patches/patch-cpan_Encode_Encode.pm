$NetBSD: patch-cpan_Encode_Encode.pm,v 1.2 2021/08/20 22:37:34 kim Exp $

perl5: patch Encode.pm for CVE-2021-36770

Without this fix, Encode::ConfigLocal can be loaded from a path relative
to the current directory, because the || operator will evaluate @INC in
scalar context, putting an integer as the only value in @INC.

Ref: https://github.com/Perl/perl5/commit/c1a937fef07c061600a0078f4cb53fe9c2136bb9.patch

--- cpan/Encode/Encode.pm.orig	2021-01-20 23:04:44.000000000 +0000
+++ cpan/Encode/Encode.pm	2021-08-20 21:36:16.700846398 +0000
@@ -65,8 +67,8 @@ require Encode::Config;
 eval {
     local $SIG{__DIE__};
     local $SIG{__WARN__};
-    local @INC = @INC || ();
-    pop @INC if $INC[-1] eq '.';
+    local @INC = @INC;
+    pop @INC if @INC && $INC[-1] eq '.';
     require Encode::ConfigLocal;
 };
 
