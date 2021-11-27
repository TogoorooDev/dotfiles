$NetBSD: patch-layer12.c,v 1.1 2019/07/10 20:01:57 nia Exp $

Fixes for CVE-2017-8372, CVE-2017-8373, CVE-2017-8374.

From Kurt Roeckx / Debian.

--- layer12.c.orig	2004-02-05 09:02:39.000000000 +0000
+++ layer12.c
@@ -72,10 +72,18 @@ mad_fixed_t const linear_table[14] = {
  * DESCRIPTION:	decode one requantized Layer I sample from a bitstream
  */
 static
-mad_fixed_t I_sample(struct mad_bitptr *ptr, unsigned int nb)
+mad_fixed_t I_sample(struct mad_bitptr *ptr, unsigned int nb, struct mad_stream *stream)
 {
   mad_fixed_t sample;
+  struct mad_bitptr frameend_ptr;
 
+  mad_bit_init(&frameend_ptr, stream->next_frame);
+
+  if (mad_bit_length(ptr, &frameend_ptr) < nb) {
+    stream->error = MAD_ERROR_LOSTSYNC;
+    stream->sync = 0;
+    return 0;
+  }
   sample = mad_bit_read(ptr, nb);
 
   /* invert most significant bit, extend sign, then scale to fixed format */
@@ -106,6 +114,10 @@ int mad_layer_I(struct mad_stream *strea
   struct mad_header *header = &frame->header;
   unsigned int nch, bound, ch, s, sb, nb;
   unsigned char allocation[2][32], scalefactor[2][32];
+  struct mad_bitptr bufend_ptr, frameend_ptr;
+
+  mad_bit_init(&bufend_ptr, stream->bufend);
+  mad_bit_init(&frameend_ptr, stream->next_frame);
 
   nch = MAD_NCHANNELS(header);
 
@@ -118,6 +130,11 @@ int mad_layer_I(struct mad_stream *strea
   /* check CRC word */
 
   if (header->flags & MAD_FLAG_PROTECTION) {
+    if (mad_bit_length(&stream->ptr, &bufend_ptr)
+		< 4 * (bound * nch + (32 - bound))) {
+      stream->error = MAD_ERROR_BADCRC;
+      return -1;
+    }
     header->crc_check =
       mad_bit_crc(stream->ptr, 4 * (bound * nch + (32 - bound)),
 		  header->crc_check);
@@ -133,6 +150,11 @@ int mad_layer_I(struct mad_stream *strea
 
   for (sb = 0; sb < bound; ++sb) {
     for (ch = 0; ch < nch; ++ch) {
+      if (mad_bit_length(&stream->ptr, &frameend_ptr) < 4) {
+	stream->error = MAD_ERROR_LOSTSYNC;
+	stream->sync = 0;
+	return -1;
+      }
       nb = mad_bit_read(&stream->ptr, 4);
 
       if (nb == 15) {
@@ -145,6 +167,11 @@ int mad_layer_I(struct mad_stream *strea
   }
 
   for (sb = bound; sb < 32; ++sb) {
+    if (mad_bit_length(&stream->ptr, &frameend_ptr) < 4) {
+      stream->error = MAD_ERROR_LOSTSYNC;
+      stream->sync = 0;
+      return -1;
+    }
     nb = mad_bit_read(&stream->ptr, 4);
 
     if (nb == 15) {
@@ -161,6 +188,11 @@ int mad_layer_I(struct mad_stream *strea
   for (sb = 0; sb < 32; ++sb) {
     for (ch = 0; ch < nch; ++ch) {
       if (allocation[ch][sb]) {
+        if (mad_bit_length(&stream->ptr, &frameend_ptr) < 6) {
+	  stream->error = MAD_ERROR_LOSTSYNC;
+	  stream->sync = 0;
+	  return -1;
+	}
 	scalefactor[ch][sb] = mad_bit_read(&stream->ptr, 6);
 
 # if defined(OPT_STRICT)
@@ -185,8 +217,10 @@ int mad_layer_I(struct mad_stream *strea
       for (ch = 0; ch < nch; ++ch) {
 	nb = allocation[ch][sb];
 	frame->sbsample[ch][s][sb] = nb ?
-	  mad_f_mul(I_sample(&stream->ptr, nb),
+	  mad_f_mul(I_sample(&stream->ptr, nb, stream),
 		    sf_table[scalefactor[ch][sb]]) : 0;
+	if (stream->error != 0)
+	  return -1;
       }
     }
 
@@ -194,7 +228,14 @@ int mad_layer_I(struct mad_stream *strea
       if ((nb = allocation[0][sb])) {
 	mad_fixed_t sample;
 
-	sample = I_sample(&stream->ptr, nb);
+	if (mad_bit_length(&stream->ptr, &frameend_ptr) < nb) {
+	  stream->error = MAD_ERROR_LOSTSYNC;
+	  stream->sync = 0;
+          return -1;
+	}
+	sample = I_sample(&stream->ptr, nb, stream);
+        if (stream->error != 0)
+	  return -1;
 
 	for (ch = 0; ch < nch; ++ch) {
 	  frame->sbsample[ch][s][sb] =
@@ -280,13 +321,21 @@ struct quantclass {
 static
 void II_samples(struct mad_bitptr *ptr,
 		struct quantclass const *quantclass,
-		mad_fixed_t output[3])
+		mad_fixed_t output[3], struct mad_stream *stream)
 {
   unsigned int nb, s, sample[3];
+  struct mad_bitptr frameend_ptr;
+
+  mad_bit_init(&frameend_ptr, stream->next_frame);
 
   if ((nb = quantclass->group)) {
     unsigned int c, nlevels;
 
+    if (mad_bit_length(ptr, &frameend_ptr) < quantclass->bits) {
+      stream->error = MAD_ERROR_LOSTSYNC;
+      stream->sync = 0;
+      return;
+    }
     /* degrouping */
     c = mad_bit_read(ptr, quantclass->bits);
     nlevels = quantclass->nlevels;
@@ -299,8 +348,14 @@ void II_samples(struct mad_bitptr *ptr,
   else {
     nb = quantclass->bits;
 
-    for (s = 0; s < 3; ++s)
+    for (s = 0; s < 3; ++s) {
+      if (mad_bit_length(ptr, &frameend_ptr) < nb) {
+	stream->error = MAD_ERROR_LOSTSYNC;
+	stream->sync = 0;
+	return;
+      }
       sample[s] = mad_bit_read(ptr, nb);
+    }
   }
 
   for (s = 0; s < 3; ++s) {
@@ -336,6 +391,9 @@ int mad_layer_II(struct mad_stream *stre
   unsigned char const *offsets;
   unsigned char allocation[2][32], scfsi[2][32], scalefactor[2][32][3];
   mad_fixed_t samples[3];
+  struct mad_bitptr frameend_ptr;
+
+  mad_bit_init(&frameend_ptr, stream->next_frame);
 
   nch = MAD_NCHANNELS(header);
 
@@ -402,13 +460,24 @@ int mad_layer_II(struct mad_stream *stre
   for (sb = 0; sb < bound; ++sb) {
     nbal = bitalloc_table[offsets[sb]].nbal;
 
-    for (ch = 0; ch < nch; ++ch)
+    for (ch = 0; ch < nch; ++ch) {
+      if (mad_bit_length(&stream->ptr, &frameend_ptr) < nbal) {
+	stream->error = MAD_ERROR_LOSTSYNC;
+	stream->sync = 0;
+	return -1;
+      }
       allocation[ch][sb] = mad_bit_read(&stream->ptr, nbal);
+    }
   }
 
   for (sb = bound; sb < sblimit; ++sb) {
     nbal = bitalloc_table[offsets[sb]].nbal;
 
+    if (mad_bit_length(&stream->ptr, &frameend_ptr) < nbal) {
+      stream->error = MAD_ERROR_LOSTSYNC;
+      stream->sync = 0;
+      return -1;
+    }
     allocation[0][sb] =
     allocation[1][sb] = mad_bit_read(&stream->ptr, nbal);
   }
@@ -417,8 +486,14 @@ int mad_layer_II(struct mad_stream *stre
 
   for (sb = 0; sb < sblimit; ++sb) {
     for (ch = 0; ch < nch; ++ch) {
-      if (allocation[ch][sb])
+      if (allocation[ch][sb]) {
+	if (mad_bit_length(&stream->ptr, &frameend_ptr) < 2) {
+	  stream->error = MAD_ERROR_LOSTSYNC;
+	  stream->sync = 0;
+	  return -1;
+	}
 	scfsi[ch][sb] = mad_bit_read(&stream->ptr, 2);
+      }
     }
   }
 
@@ -441,6 +516,11 @@ int mad_layer_II(struct mad_stream *stre
   for (sb = 0; sb < sblimit; ++sb) {
     for (ch = 0; ch < nch; ++ch) {
       if (allocation[ch][sb]) {
+	if (mad_bit_length(&stream->ptr, &frameend_ptr) < 6) {
+	  stream->error = MAD_ERROR_LOSTSYNC;
+	  stream->sync = 0;
+	  return -1;
+	}
 	scalefactor[ch][sb][0] = mad_bit_read(&stream->ptr, 6);
 
 	switch (scfsi[ch][sb]) {
@@ -451,11 +531,21 @@ int mad_layer_II(struct mad_stream *stre
 	  break;
 
 	case 0:
+	  if (mad_bit_length(&stream->ptr, &frameend_ptr) < 6) {
+	    stream->error = MAD_ERROR_LOSTSYNC;
+	    stream->sync = 0;
+	    return -1;
+	  }
 	  scalefactor[ch][sb][1] = mad_bit_read(&stream->ptr, 6);
 	  /* fall through */
 
 	case 1:
 	case 3:
+	  if (mad_bit_length(&stream->ptr, &frameend_ptr) < 6) {
+	    stream->error = MAD_ERROR_LOSTSYNC;
+	    stream->sync = 0;
+	    return -1;
+	  }
 	  scalefactor[ch][sb][2] = mad_bit_read(&stream->ptr, 6);
 	}
 
@@ -487,7 +577,9 @@ int mad_layer_II(struct mad_stream *stre
 	if ((index = allocation[ch][sb])) {
 	  index = offset_table[bitalloc_table[offsets[sb]].offset][index - 1];
 
-	  II_samples(&stream->ptr, &qc_table[index], samples);
+	  II_samples(&stream->ptr, &qc_table[index], samples, stream);
+	  if (stream->error != 0)
+            return -1;
 
 	  for (s = 0; s < 3; ++s) {
 	    frame->sbsample[ch][3 * gr + s][sb] =
@@ -505,7 +597,9 @@ int mad_layer_II(struct mad_stream *stre
       if ((index = allocation[0][sb])) {
 	index = offset_table[bitalloc_table[offsets[sb]].offset][index - 1];
 
-	II_samples(&stream->ptr, &qc_table[index], samples);
+	II_samples(&stream->ptr, &qc_table[index], samples, stream);
+	if (stream->error != 0)
+          return -1;
 
 	for (ch = 0; ch < nch; ++ch) {
 	  for (s = 0; s < 3; ++s) {
