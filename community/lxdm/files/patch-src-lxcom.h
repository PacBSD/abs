--- src/lxcom.h.orig	2014-10-06 03:32:56.507004216 +0000
+++ src/lxcom.h	2014-10-06 03:33:32.590644433 +0000
@@ -1,6 +1,14 @@
 #ifndef _LXCOM_H_
 #define LXCOM_H_
 
+#if defined(__unix__) || defined(unix)
+#include <sys/param.h>
+#endif
+
+#if !defined(_WANT_UCRED)
+	#define _WANT_UCRED
+#endif
+
 void lxcom_init(const char *sock);
 void lxcom_raise_signal(int sig);
 gboolean lxcom_send(const char *sock,const char *buf,char **res);
