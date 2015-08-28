--- loudmouth/lm-ssl-gnutls.c.orig	2010-04-17 15:56:39.000000000 -0400
+++ loudmouth/lm-ssl-gnutls.c	2010-04-17 15:56:43.000000000 -0400
@@ -32,7 +32,7 @@
 
 #include <gnutls/x509.h>
 
-#define CA_PEM_FILE "/etc/ssl/certs/ca-certificates.crt"
+#define CA_PEM_FILE "/usr/share/certs/ca-root-nss.crt"
 
 struct _LmSSL {
 	LmSSLBase base;
