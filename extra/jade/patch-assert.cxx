--- lib/assert.cxx	2013-02-25 09:53:26.000000000 +0000
+++ lib/assert.cxx.new	2013-02-25 09:54:42.000000000 +0000
@@ -6,7 +6,7 @@
 #include "macros.h"
 
 #ifdef __GNUG__
-void exit (int __status) __THROW __attribute__ ((__noreturn__));
+void exit (int __status) __attribute__ ((__noreturn__));
 #endif
 
 #ifdef SP_NAMESPACE
