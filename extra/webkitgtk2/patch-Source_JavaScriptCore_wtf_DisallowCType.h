--- Source/WTF/wtf/DisallowCType.h.orig	2013-12-17 19:10:40.448345616 +0000
+++ Source/WTF/wtf/DisallowCType.h	2013-12-17 19:13:17.203303336 +0000
@@ -35,11 +35,19 @@
 // ASCII-specific functions instead. This header makes sure we get a compile-time
 // error if we use one of the <ctype.h> functions by accident.
 
+// Include inlined functions using <ctype.h> first to avoid compilation errors
+#ifdef __cplusplus
+#include <cwchar>
+#include <cwctype>
+#include <string>
+#endif
+
 // this breaks compilation of <QFontDatabase>, at least, so turn it off for now
 // Also generates errors on wx on Windows, presumably because these functions
 // are used from wx headers. On GTK+ for Mac many GTK+ files include <libintl.h>
 // or <glib/gi18n-lib.h>, which in turn include <xlocale/_ctype.h> which uses
 // isacii(). 
+
 #include <wtf/Platform.h>
 #if !PLATFORM(QT) && !PLATFORM(WX) && !PLATFORM(CHROMIUM) && !(OS(DARWIN) && PLATFORM(GTK)) && !OS(QNX) && !defined(_LIBCPP_VERSION)
 
