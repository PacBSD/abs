--- lib/x509/rfc2818_hostname.c.orig	2014-09-11 13:09:41.700641125 +0000
+++ lib/x509/rfc2818_hostname.c	2014-09-11 13:10:29.448181597 +0000
@@ -25,6 +25,7 @@
 #include <common.h>
 #include <gnutls_errors.h>
 #include <system.h>
+#include <netinet/in.h>
 
 /**
  * gnutls_x509_crt_check_hostname:
