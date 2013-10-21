--- config.h.orig	2013-08-06 07:55:00.289637339 +0200
+++ config.h	2013-08-06 07:55:05.646631276 +0200
@@ -119,7 +119,7 @@
 #define USE_SYS_ENDIAN_H 1
 
 /* Build support for XAA */
-#define USE_XAA 1
+#undef USE_XAA
 
 /* Version number of package */
 #define VERSION "6.14.6"
