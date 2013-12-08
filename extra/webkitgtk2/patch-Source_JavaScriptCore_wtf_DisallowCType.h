--- Source/WTF/wtf/DisallowCType.h.orig	2013-09-10 12:27:15.000000000 +0200
+++ Source/WTF/wtf/DisallowCType.h	2013-09-10 12:28:32.000000000 +0200
@@ -35,7 +35,13 @@
 // ASCII-specific functions instead. This header makes sure we get a compile-time
 // error if we use one of the <ctype.h> functions by accident.
 
+// Include inlined functions using <ctype.h> first to avoid compilation errors
+#ifdef __cplusplus
+#include <cwchar>
+#include <cwctype>
+#include <string>
+#endif
 
 #include <ctype.h>
 
 #undef isalnum
