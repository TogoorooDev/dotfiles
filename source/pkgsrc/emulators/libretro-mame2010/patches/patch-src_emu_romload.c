$NetBSD: patch-src_emu_romload.c,v 1.2 2021/06/19 07:23:31 nia Exp $

Consistently build as C++11 source, but ignore narrow issues.
Don't depend on ordering of pointers relative to zero. Avoid UDL.

--- src/emu/romload.c.orig	2020-05-13 15:21:49.756367021 +0000
+++ src/emu/romload.c
@@ -586,13 +586,13 @@ static void display_rom_load_results(rom
 	{
 		/* create the error message and exit fatally */
 		mame_printf_error("%s", romdata->errorstring.cstr());
-		fatalerror_exitcode(romdata->machine, MAMERR_MISSING_FILES, "ERROR: required files are missing, the "GAMENOUN" cannot be run.");
+		fatalerror_exitcode(romdata->machine, MAMERR_MISSING_FILES, "ERROR: required files are missing, the " GAMENOUN " cannot be run.");
 	}
 
 	/* if we had warnings, output them, but continue */
 	if (romdata->warnings)
 	{
-		romdata->errorstring.cat("WARNING: the "GAMENOUN" might not run correctly.");
+		romdata->errorstring.cat("WARNING: the " GAMENOUN " might not run correctly.");
 		mame_printf_warning("%s\n", romdata->errorstring.cstr());
 	}
 }
