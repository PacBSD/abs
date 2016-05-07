--- md5/md5.c.orig	2014-08-30 13:52:09 UTC
+++ md5/md5.c
@@ -45,6 +45,8 @@ static void MD5Transform(unsigned int [4
 #include <libkern/OSByteOrder.h>
 #define le32toh(x) OSSwapLittleToHostInt32(x)
 #define htole32(x) OSSwapHostToLittleInt32(x)
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #endif
 
 /*
