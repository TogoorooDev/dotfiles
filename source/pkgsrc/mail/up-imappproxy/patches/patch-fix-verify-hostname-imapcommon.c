Fix TLS verification to set hostname.

Patch from OpenBSD
Reported by Stuart Henderson

--- src/imapcommon.c.orig
+++ src/imapcommon.c
@@ -169,6 +169,7 @@ extern ProxyConfig_Struct PC_Struct;
 static int send_queued_preauth_commands( char *, ITD_Struct * );
 
 #if HAVE_LIBSSL
+#include <openssl/x509v3.h>
 extern SSL_CTX *tls_ctx;
 
 /*++
@@ -369,6 +370,7 @@ extern void UnLockMutex( pthread_mutex_t *mutex )
 extern int Attempt_STARTTLS( ITD_Struct *Server )
 {
     char *fn = "Attempt_STARTTLS()";
+    X509_VERIFY_PARAM *param = NULL;
 
     unsigned int BufLen = BUFSIZE - 1;
     char SendBuf[BUFSIZE];
@@ -467,6 +469,15 @@ extern int Attempt_STARTTLS( ITD_Struct *Server )
 	{
 	    syslog(LOG_INFO,
 		    "STARTTLS failed: SSL_set_fd() failed: %d",
+		    SSL_get_error( Server->conn->tls, rc ) );
+	    goto fail;
+	}
+
+	param = SSL_get0_param(Server->conn->tls);
+	X509_VERIFY_PARAM_set_hostflags(param, X509_CHECK_FLAG_NO_PARTIAL_WILDCARDS);
+	if (!X509_VERIFY_PARAM_set1_host(param, PC_Struct.server_hostname, 0)) {
+	    syslog(LOG_INFO,
+		    "STARTTLS failed: X509_VERIFY_PARAM_set1_host() failed: %d",
 		    SSL_get_error( Server->conn->tls, rc ) );
 	    goto fail;
 	}
