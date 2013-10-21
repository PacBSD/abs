--- src/common/xchat.h.orig	2012-06-19 21:08:15.000000000 -0500
+++ src/common/xchat.h	2012-06-19 21:08:30.000000000 -0500
@@ -562,12 +562,7 @@
 /* CL: get a random int in the range [0..n-1]. DON'T use rand() % n, it gives terrible results. */
 #define RAND_INT(n) ((int)(rand() / (RAND_MAX + 1.0) * (n)))
 
-#if defined(WIN32) && GLIB_CHECK_VERSION(2,4,0)
-#define xchat_filename_from_utf8 g_locale_from_utf8
-#define xchat_filename_to_utf8 g_locale_to_utf8
-#else
 #define xchat_filename_from_utf8 g_filename_from_utf8
 #define xchat_filename_to_utf8 g_filename_to_utf8
-#endif
 
 #endif
