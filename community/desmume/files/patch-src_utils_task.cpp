--- src/utils/task.cpp.orig	2015-02-14 15:05:26.000000000 +0000
+++ src/utils/task.cpp	2015-09-21 21:57:55.012390341 +0100
@@ -26,6 +26,7 @@
 #if defined HOST_LINUX
 #include <unistd.h>
 #elif defined HOST_BSD || defined HOST_DARWIN
+#include <iostream>
 #include <sys/sysctl.h>
 #endif
 #endif // HOST_WINDOWS
