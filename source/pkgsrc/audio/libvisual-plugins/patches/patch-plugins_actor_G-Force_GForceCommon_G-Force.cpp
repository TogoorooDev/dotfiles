$NetBSD: patch-plugins_actor_G-Force_GForceCommon_G-Force.cpp,v 1.1 2020/05/26 11:25:02 joerg Exp $

--- plugins/actor/G-Force/GForceCommon/G-Force.cpp.orig	2020-05-26 00:17:08.719115589 +0000
+++ plugins/actor/G-Force/GForceCommon/G-Force.cpp
@@ -624,7 +624,7 @@ void GForce::ManageColorChanges() {
 		// If in a ColorMap transition/morph then we must set mColorTrans, for it's linked into mGF_Palette
 		if ( mColorTransTime > 0 ) {
 			float t = (float) ( mColorTransEnd - mT_MS ) / ( (float) mColorTransTime );
-			mColorTrans = pow( t, TRANSITION_ALPHA );
+			mColorTrans = pow( t, float(TRANSITION_ALPHA) );
 		} 
 		
 		// Evaluate the palette at this time	
@@ -983,7 +983,7 @@ void GForce::RecordSample( long inCurTim
 		// Is the text is about to expire? if not, continue drawing.
 		if ( t <= 1 ) {
 		
-			intensity = 255.5 * pow( t, 1.5 );  
+			intensity = 255.5 * pow( t, 1.5f );  
 			mCurPort -> SetTextColor( mPalette[ intensity ] );
 			mCurPort -> SetTrackTextFont();
 			mCurPort -> DrawText( mTrackTextPos.h, mTrackTextPos.v, mTrackText ); }
