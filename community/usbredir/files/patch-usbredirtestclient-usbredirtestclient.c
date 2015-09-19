--- usbredirtestclient/usbredirtestclient.c.orig	2015-09-19 23:15:45.967954426 +0100
+++ usbredirtestclient/usbredirtestclient.c	2015-09-19 23:15:58.158451214 +0100
@@ -36,6 +36,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include "usbredirparser.h"
 
 /* Macros to go from an endpoint address to an index for our ep array */
