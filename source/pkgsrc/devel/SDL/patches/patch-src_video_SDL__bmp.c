$NetBSD: patch-src_video_SDL__bmp.c,v 1.2 2020/05/14 14:44:17 nia Exp $

CVE-2019-7635: Reject BMP images with pixel colors out the palette
From upstream hg 12831:f1f5878be5db

CVE-2019-7636, CVE-2019-7638
From upstream hg 12612:07c39cbbeacf

CVE-2019-13616: validate image size when loading BMP files
From upstream hg 12960:ad1bbfbca760

Reject 2, 3, 5, 6, 7-bpp BMP images
From upstreah hg 12646:4646533663ae

--- src/video/SDL_bmp.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/SDL_bmp.c
@@ -143,6 +143,11 @@ SDL_Surface * SDL_LoadBMP_RW (SDL_RWops 
 	(void) biYPelsPerMeter;
 	(void) biClrImportant;
 
+	if (biWidth <= 0 || biHeight == 0) {
+		SDL_SetError("BMP file with bad dimensions (%dx%d)", biWidth, biHeight);
+		was_error = SDL_TRUE;
+		goto done;
+	}
 	if (biHeight < 0) {
 		topDown = SDL_TRUE;
 		biHeight = -biHeight;
@@ -163,6 +168,14 @@ SDL_Surface * SDL_LoadBMP_RW (SDL_RWops 
 			ExpandBMP = biBitCount;
 			biBitCount = 8;
 			break;
+		case 2:
+		case 3:
+		case 5:
+		case 6:
+		case 7:
+			SDL_SetError("%d-bpp BMP images are not supported", biBitCount);
+			was_error = SDL_TRUE;
+			goto done;
 		default:
 			ExpandBMP = 0;
 			break;
@@ -233,6 +246,10 @@ SDL_Surface * SDL_LoadBMP_RW (SDL_RWops 
 	if ( palette ) {
 		if ( biClrUsed == 0 ) {
 			biClrUsed = 1 << biBitCount;
+		} else if (biClrUsed > (1 << biBitCount)) {
+			SDL_SetError("BMP file has an invalid number of colors");
+			was_error = SDL_TRUE;
+			goto done;
 		}
 		if ( biSize == 12 ) {
 			for ( i = 0; i < (int)biClrUsed; ++i ) {
@@ -296,6 +313,12 @@ SDL_Surface * SDL_LoadBMP_RW (SDL_RWops 
 				}
 				*(bits+i) = (pixel>>shift);
 				pixel <<= ExpandBMP;
+				if ( bits[i] >= biClrUsed ) {
+					SDL_SetError(
+						"A BMP image contains a pixel with a color out of the palette");
+					was_error = SDL_TRUE;
+					goto done;
+				}
 			} }
 			break;
 
@@ -306,6 +329,16 @@ SDL_Surface * SDL_LoadBMP_RW (SDL_RWops 
 				was_error = SDL_TRUE;
 				goto done;
 			}
+			if ( 8 == biBitCount && palette && biClrUsed < (1 << biBitCount ) ) {
+				for ( i=0; i<surface->w; ++i ) {
+					if ( bits[i] >= biClrUsed ) {
+						SDL_SetError(
+							"A BMP image contains a pixel with a color out of the palette");
+						was_error = SDL_TRUE;
+						goto done;
+					}
+				}
+			}
 #if SDL_BYTEORDER == SDL_BIG_ENDIAN
 			/* Byte-swap the pixels if needed. Note that the 24bpp
 			   case has already been taken care of above. */
