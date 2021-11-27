$NetBSD: patch-bz2.c,v 1.3 2021/02/05 16:46:25 taca Exp $

* Update API for newer versions of Ruby.

--- bz2.c.orig	2004-12-04 14:36:59.000000000 +0000
+++ bz2.c
@@ -1,7 +1,15 @@
 #include <ruby.h>
+#ifdef HAVE_RUBY_IO_H
+#include <ruby/io.h>
+#else
 #include <rubyio.h>
+#endif
 #include <bzlib.h>
+#ifdef HAVE_RUBY_VERSION_H
+#include <ruby/version.h>
+#else
 #include <version.h>
+#endif
 
 static VALUE bz_cWriter, bz_cReader, bz_cInternal;
 static VALUE bz_eError, bz_eConfigError, bz_eEOZError;
@@ -109,11 +117,11 @@ bz_find_struct(obj, ptr, posp)
     struct bz_iv *bziv;
     int i;
 
-    for (i = 0; i < RARRAY(bz_internal_ary)->len; i++) {
-	Data_Get_Struct(RARRAY(bz_internal_ary)->ptr[i], struct bz_iv, bziv);
+    for (i = 0; i < RARRAY_LEN(bz_internal_ary); i++) {
+	Data_Get_Struct(RARRAY_PTR(bz_internal_ary)[i], struct bz_iv, bziv);
 	if (ptr) {
 	    if (TYPE(bziv->io) == T_FILE && 
-		RFILE(bziv->io)->fptr == (OpenFile *)ptr) {
+		RFILE(bziv->io)->fptr == (rb_io_t *)ptr) {
 		if (posp) *posp = i;
 		return bziv;
 	    }
@@ -215,8 +223,8 @@ bz_internal_finalize(ary, obj)
     struct bz_iv *bziv;
     struct bz_file *bzf;
 
-    for (i = 0; i < RARRAY(bz_internal_ary)->len; i++) {
-	elem = RARRAY(bz_internal_ary)->ptr[i];
+    for (i = 0; i < RARRAY_LEN(bz_internal_ary); i++) {
+	elem = RARRAY_PTR(bz_internal_ary)[i];
 	Data_Get_Struct(elem, struct bz_iv, bziv);
 	if (bziv->bz2) {
 	    RDATA(bziv->bz2)->dfree = ruby_xfree;
@@ -249,7 +257,7 @@ bz_writer_close(obj)
     Get_BZ2(obj, bzf);
     res = bz_writer_internal_close(bzf);
     if (!NIL_P(res) && (bzf->flags & BZ2_RB_INTERNAL)) {
-	RBASIC(res)->klass = rb_cString;
+	rb_obj_reveal(res, rb_cString);
     }
     return res;
 }
@@ -301,7 +309,8 @@ bz_io_data_finalize(ptr)
 	    (*bziv->finalize)(ptr);
 	}
 	else if (TYPE(bzf->io) == T_FILE) {
-	    OpenFile *file = (OpenFile *)ptr;
+	    rb_io_t *file = (rb_io_t *)ptr;
+#ifndef HAVE_RUBY_IO_H
 	    if (file->f) {
 		fclose(file->f);
 		file->f = 0;
@@ -310,6 +319,16 @@ bz_io_data_finalize(ptr)
 		fclose(file->f2);
 		file->f2 = 0;
 	    }
+#else
+	    if (file->fd) {
+		close(file->fd);
+		file->fd = -1;
+	    }
+	    if (file->stdio_file) {
+		fclose(file->stdio_file);
+		file->stdio_file = 0;
+	    }
+#endif
 	}
     }
 }
@@ -396,8 +415,8 @@ bz_str_write(obj, str)
     if (TYPE(str) != T_STRING) {
 	rb_raise(rb_eArgError, "expected a String");
     }
-    if (RSTRING(str)->len) {
-	rb_str_cat(obj, RSTRING(str)->ptr, RSTRING(str)->len);
+    if (RSTRING_LEN(str)) {
+	rb_str_cat(obj, RSTRING_PTR(str), RSTRING_LEN(str));
     }
     return str;
 }
@@ -436,7 +455,7 @@ bz_writer_init(argc, argv, obj)
     else {
 	VALUE iv;
 	struct bz_iv *bziv;
-	OpenFile *fptr;
+	rb_io_t *fptr;
 
 	rb_io_taint_check(a);
 	if (!rb_respond_to(a, id_write)) {
@@ -460,7 +479,7 @@ bz_writer_init(argc, argv, obj)
 	    bziv->bz2 = obj;
 	}
 	else {
-	    iv = Data_Make_Struct(rb_cData, struct bz_iv, 0, free, bziv);
+	    iv = Data_Make_Struct(rb_cObject, struct bz_iv, 0, free, bziv);
 	    bziv->io = a;
 	    bziv->bz2 = obj;
 	    rb_ary_push(bz_internal_ary, iv);
@@ -507,8 +526,8 @@ bz_writer_write(obj, a)
 	bzf->buflen = BZ_RB_BLOCKSIZE;
 	bzf->buf[0] = bzf->buf[bzf->buflen] = '\0';
     }
-    bzf->bzs.next_in = RSTRING(a)->ptr;
-    bzf->bzs.avail_in = RSTRING(a)->len;
+    bzf->bzs.next_in = RSTRING_PTR(a);
+    bzf->bzs.avail_in = RSTRING_LEN(a);
     while (bzf->bzs.avail_in) {
 	bzf->bzs.next_out = bzf->buf;
 	bzf->bzs.avail_out = bzf->buflen;
@@ -523,7 +542,7 @@ bz_writer_write(obj, a)
 	    rb_funcall(bzf->io, id_write, 1, rb_str_new(bzf->buf, n));
 	}
     }
-    return INT2NUM(RSTRING(a)->len);
+    return INT2NUM(RSTRING_LEN(a));
 }
 
 static VALUE
@@ -614,7 +633,7 @@ bz_reader_init(argc, argv, obj)
     }
     if (rb_respond_to(a, id_read)) {
 	if (TYPE(a) == T_FILE) {
-	    OpenFile *fptr;
+	    rb_io_t *fptr;
 
 	    GetOpenFile(a, fptr);
 	    rb_io_check_readable(fptr);
@@ -691,14 +710,14 @@ bz_next_available(bzf, in)
     }
     if (!bzf->bzs.avail_in) {
 	bzf->in = rb_funcall(bzf->io, id_read, 1, INT2FIX(1024));
-	if (TYPE(bzf->in) != T_STRING || RSTRING(bzf->in)->len == 0) {
+	if (TYPE(bzf->in) != T_STRING || RSTRING_LEN(bzf->in) == 0) {
 	    BZ2_bzDecompressEnd(&(bzf->bzs));
 	    bzf->bzs.avail_out = 0;
 	    bzf->state = BZ_UNEXPECTED_EOF;
 	    bz_raise(bzf->state);
 	}
-	bzf->bzs.next_in = RSTRING(bzf->in)->ptr;
-	bzf->bzs.avail_in = RSTRING(bzf->in)->len;
+	bzf->bzs.next_in = RSTRING_PTR(bzf->in);
+	bzf->bzs.avail_in = RSTRING_LEN(bzf->in);
     }
     if ((bzf->buflen - in) < (BZ_RB_BLOCKSIZE / 2)) {
 	bzf->buf = REALLOC_N(bzf->buf, char, bzf->buflen+BZ_RB_BLOCKSIZE+1);
@@ -780,7 +799,7 @@ bz_read_until(bzf, str, len, td1)
 	    if (nex) {
 		res = rb_str_cat(res, bzf->buf, nex);
 	    }
-	    if (RSTRING(res)->len) {
+	    if (RSTRING_LEN(res)) {
 		return res;
 	    }
 	    return Qnil;
@@ -845,8 +864,8 @@ bz_reader_read(argc, argv, obj)
     }
     while (1) {
 	total = bzf->bzs.avail_out;
-	if (n != -1 && (RSTRING(res)->len + total) >= n) {
-	    n -= RSTRING(res)->len;
+	if (n != -1 && (RSTRING_LEN(res) + total) >= n) {
+	    n -= RSTRING_LEN(res);
 	    res = rb_str_cat(res, bzf->bzs.next_out, n);
 	    bzf->bzs.next_out += n;
 	    bzf->bzs.avail_out -= n;
@@ -868,10 +887,10 @@ bz_getc(obj)
 {
     VALUE length = INT2FIX(1);
     VALUE res = bz_reader_read(1, &length, obj);
-    if (NIL_P(res) || RSTRING(res)->len == 0) {
+    if (NIL_P(res) || RSTRING_LEN(res) == 0) {
 	return EOF;
     }
-    return RSTRING(res)->ptr[0];
+    return RSTRING_PTR(res)[0];
 }
 
 static VALUE
@@ -911,15 +930,15 @@ bz_reader_ungets(obj, a)
     if (!bzf->buf) {
 	bz_raise(BZ_SEQUENCE_ERROR);
     }
-    if ((bzf->bzs.avail_out + RSTRING(a)->len) < bzf->buflen) {
-	bzf->bzs.next_out -= RSTRING(a)->len;
-	MEMCPY(bzf->bzs.next_out, RSTRING(a)->ptr, char, RSTRING(a)->len);
-	bzf->bzs.avail_out += RSTRING(a)->len;
+    if ((bzf->bzs.avail_out + RSTRING_LEN(a)) < bzf->buflen) {
+	bzf->bzs.next_out -= RSTRING_LEN(a);
+	MEMCPY(bzf->bzs.next_out, RSTRING_PTR(a), char, RSTRING_LEN(a));
+	bzf->bzs.avail_out += RSTRING_LEN(a);
     }
     else {
-	bzf->buf = REALLOC_N(bzf->buf, char, bzf->buflen + RSTRING(a)->len + 1);
-	MEMCPY(bzf->buf + bzf->buflen, RSTRING(a)->ptr, char,RSTRING(a)->len);
-	bzf->buflen += RSTRING(a)->len;
+	bzf->buf = REALLOC_N(bzf->buf, char, bzf->buflen + RSTRING_LEN(a) + 1);
+	MEMCPY(bzf->buf + bzf->buflen, RSTRING_PTR(a), char,RSTRING_LEN(a));
+	bzf->buflen += RSTRING_LEN(a);
 	bzf->buf[bzf->buflen] = '\0';
 	bzf->bzs.next_out = bzf->buf;
 	bzf->bzs.avail_out = bzf->buflen;
@@ -966,8 +985,8 @@ bz_reader_gets_internal(argc, argv, obj,
     if (NIL_P(rs)) {
 	return bz_reader_read(1, &rs, obj);
     }
-    rslen = RSTRING(rs)->len;
-    if (rs == rb_default_rs || (rslen == 1 && RSTRING(rs)->ptr[0] == '\n')) {
+    rslen = RSTRING_LEN(rs);
+    if (rs == rb_default_rs || (rslen == 1 && RSTRING_PTR(rs)[0] == '\n')) {
 	return bz_reader_gets(obj);
     }
 
@@ -977,7 +996,7 @@ bz_reader_gets_internal(argc, argv, obj,
 	rspara = 1;
     }
     else {
-	rsptr = RSTRING(rs)->ptr;
+	rsptr = RSTRING_PTR(rs);
 	rspara = 0;
     }
 
@@ -1024,13 +1043,13 @@ bz_reader_set_unused(obj, a)
     Check_Type(a, T_STRING);
     Get_BZ2(obj, bzf);
     if (!bzf->in) {
-	bzf->in = rb_str_new(RSTRING(a)->ptr, RSTRING(a)->len);
+	bzf->in = rb_str_new(RSTRING_PTR(a), RSTRING_LEN(a));
     }
     else {
-	bzf->in = rb_str_cat(bzf->in, RSTRING(a)->ptr, RSTRING(a)->len);
+	bzf->in = rb_str_cat(bzf->in, RSTRING_PTR(a), RSTRING_LEN(a));
     }
-    bzf->bzs.next_in = RSTRING(bzf->in)->ptr;
-    bzf->bzs.avail_in = RSTRING(bzf->in)->len;
+    bzf->bzs.next_in = RSTRING_PTR(bzf->in);
+    bzf->bzs.avail_in = RSTRING_LEN(bzf->in);
     return Qnil;
 }
 
@@ -1042,10 +1061,10 @@ bz_reader_getc(obj)
     VALUE len = INT2FIX(1);
 
     str = bz_reader_read(1, &len, obj);
-    if (NIL_P(str) || RSTRING(str)->len == 0) {
+    if (NIL_P(str) || RSTRING_LEN(str) == 0) {
 	return Qnil;
     }
-    return INT2FIX(RSTRING(str)->ptr[0] & 0xff);
+    return INT2FIX(RSTRING_PTR(str)[0] & 0xff);
 }
 
 static void
@@ -1319,7 +1338,7 @@ bz_reader_s_foreach(argc, argv, obj)
 	rb_raise(rb_eArgError, "call out of a block");
     }
     rb_scan_args(argc, argv, "11", &fname, &sep);
-    Check_SafeStr(fname);
+    SafeStringValue(fname);
     arg.argc = argc - 1;
     arg.sep = sep;
     arg.obj = rb_funcall2(rb_mKernel, id_open, 1, &fname);
@@ -1357,7 +1376,7 @@ bz_reader_s_readlines(argc, argv, obj)
     struct bz_file *bzf;
 
     rb_scan_args(argc, argv, "11", &fname, &sep);
-    Check_SafeStr(fname);
+    SafeStringValue(fname);
     arg.argc = argc - 1;
     arg.sep = sep;
     arg.obj = rb_funcall2(rb_mKernel, id_open, 1, &fname);
@@ -1411,7 +1430,7 @@ bz_str_read(argc, argv, obj)
     Data_Get_Struct(obj, struct bz_str, bzs);
     rb_scan_args(argc, argv, "01", &len);
     if (NIL_P(len)) {
-	count = RSTRING(bzs->str)->len;
+	count = RSTRING_LEN(bzs->str);
     }
     else {
 	count = NUM2INT(len);
@@ -1422,13 +1441,13 @@ bz_str_read(argc, argv, obj)
     if (!count || bzs->pos == -1) {
 	return Qnil;
     }
-    if ((bzs->pos + count) >= RSTRING(bzs->str)->len) {
-	res = rb_str_new(RSTRING(bzs->str)->ptr + bzs->pos, 
-			 RSTRING(bzs->str)->len - bzs->pos);
+    if ((bzs->pos + count) >= RSTRING_LEN(bzs->str)) {
+	res = rb_str_new(RSTRING_PTR(bzs->str) + bzs->pos, 
+			 RSTRING_LEN(bzs->str) - bzs->pos);
 	bzs->pos = -1;
     }
     else {
-	res = rb_str_new(RSTRING(bzs->str)->ptr + bzs->pos, count);
+	res = rb_str_new(RSTRING_PTR(bzs->str) + bzs->pos, count);
 	bzs->pos += count;
     }
     return res;
@@ -1464,7 +1483,7 @@ bz_proc_new(func, val)
     VALUE (*func)(ANYARGS);
     VALUE val;
 {
-    VALUE tmp = Data_Wrap_Struct(rb_cData, 0, 0, 0);
+    VALUE tmp = Data_Wrap_Struct(rb_cObject, 0, 0, 0);
     rb_define_singleton_method(tmp, "tmp_proc", func, 1);
     return rb_funcall2(rb_funcall(tmp, rb_intern("method"), 1, 
                                   ID2SYM(rb_intern("tmp_proc"))),
@@ -1507,7 +1526,7 @@ void Init_bz2()
     /*
       Writer
     */
-    bz_cWriter = rb_define_class_under(bz_mBZ2, "Writer", rb_cData);
+    bz_cWriter = rb_define_class_under(bz_mBZ2, "Writer", rb_cObject);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_define_alloc_func(bz_cWriter, bz_writer_s_alloc);
 #else
@@ -1530,7 +1549,7 @@ void Init_bz2()
     /*
       Reader
     */
-    bz_cReader = rb_define_class_under(bz_mBZ2, "Reader", rb_cData);
+    bz_cReader = rb_define_class_under(bz_mBZ2, "Reader", rb_cObject);
     rb_include_module(bz_cReader, rb_mEnumerable);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_define_alloc_func(bz_cReader, bz_reader_s_alloc);
@@ -1570,7 +1589,7 @@ void Init_bz2()
     /*
       Internal
     */
-    bz_cInternal = rb_define_class_under(bz_mBZ2, "InternalStr", rb_cData);
+    bz_cInternal = rb_define_class_under(bz_mBZ2, "InternalStr", rb_cObject);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_undef_alloc_func(bz_cInternal);
 #else
