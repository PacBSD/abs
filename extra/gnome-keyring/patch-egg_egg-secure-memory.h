--- egg/egg-secure-memory.h.orig	Wed Sep 26 10:28:35 2012
+++ egg/egg-secure-memory.h	Sat Oct 27 14:46:28 2012
@@ -27,16 +27,16 @@
 #include <stdlib.h>
 
 /* -------------------------------------------------------------------
- * Low Level Secure Memory 
- * 
- * IMPORTANT: This is pure vanila standard C, no glib. We need this 
- * because certain consumers of this protocol need to be built 
+ * Low Level Secure Memory
+ *
+ * IMPORTANT: This is pure vanila standard C, no glib. We need this
+ * because certain consumers of this protocol need to be built
  * without linking in any special libraries. ie: the PKCS#11 module.
- * 
+ *
  * Thread locking
- * 
+ *
  * In order to use these functions in a module the following functions
- * must be defined somewhere, and provide appropriate locking for 
+ * must be defined somewhere, and provide appropriate locking for
  * secure memory between threads:
  */
 
@@ -66,12 +66,12 @@ typedef struct {
 
 extern egg_secure_glob EGG_SECURE_GLOBALS;
 
-/* 
+/*
  * Main functionality
- *  
+ *
  * Allocations return NULL on failure.
- */ 
- 
+ */
+
 #define EGG_SECURE_USE_FALLBACK     0x0001
 
 #define EGG_SECURE_DECLARE(tag) \
