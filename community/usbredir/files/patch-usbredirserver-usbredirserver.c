--- usbredirserver/usbredirserver.c.orig	2015-09-19 23:14:19.997958684 +0100
+++ usbredirserver/usbredirserver.c	2015-09-19 23:14:40.322132505 +0100
@@ -35,6 +35,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include "usbredirhost.h"
 
 
