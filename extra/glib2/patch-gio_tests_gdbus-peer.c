--- gio/tests/gdbus-peer.c	2013-10-19 16:14:25.052047025 +0100
+++ gio/tests/gdbus-peer.c.new	2013-10-19 16:15:45.743041705 +0100
@@ -44,6 +44,9 @@
 #include <errno.h>
 #endif
 
+#include <sys/socket.h>
+
+
 #if (defined(__linux__) || \
   defined(__FreeBSD__) || \
   defined(__FreeBSD_kernel__) || \
