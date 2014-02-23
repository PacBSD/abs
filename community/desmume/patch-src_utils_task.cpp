--- src/utils/task.cpp	2014-02-23 13:49:46.392127295 +0000
+++ src/utils/task.cpp.new	2014-02-23 13:51:41.374103141 +0000
@@ -26,6 +26,7 @@
 #if defined HOST_LINUX || defined HOST_DARWIN
 #include <unistd.h>
 #elif defined HOST_BSD
+#include <iostream>
 #include <sys/sysctl.h>
 #endif
 #endif // HOST_WINDOWS
@@ -41,9 +42,9 @@
 	return sysconf(_SC_NPROCESSORS_ONLN);
 #elif defined HOST_BSD
 	int cores;
-	const int mib[4] = { CTL_HW, HW_NCPU, 0, 0 };
-	const size_t len = sizeof(cores);
-	sysctl(mib, 2, &cores, &len, NULL, 0);
+        size_t len = sizeof(cores);
+        sysctlbyname("hw.ncpu", &cores, &len, NULL, 0);
+
 	return (cores < 1) ? 1 : cores;
 #else
 	return 1;
