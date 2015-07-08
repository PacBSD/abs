--- Source/WTF/wtf/Atomics.h.orig	2012-08-20 18:26:04.000000000 +0200
+++ Source/WTF/wtf/Atomics.h	2013-09-10 12:03:55.000000000 +0200
@@ -65,18 +65,10 @@
 
 #if OS(WINDOWS)
 #include <windows.h>
-#elif OS(DARWIN)
-#include <libkern/OSAtomic.h>
 #elif OS(QNX)
 #include <atomic.h>
 #elif OS(ANDROID)
 #include <sys/atomics.h>
-#elif COMPILER(GCC)
-#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))) && !defined(__LSB_VERSION__)
-#include <ext/atomicity.h>
-#else
-#include <bits/atomicity.h>
-#endif
 #endif
 
 namespace WTF {
@@ -113,8 +105,8 @@
 #elif COMPILER(GCC) & !CPU(SPARC64) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
-inline int atomicIncrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, 1) + 1; }
-inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+inline int atomicIncrement(int volatile* addend) { return __sync_add_and_fetch(addend, 1); } 
+inline int atomicDecrement(int volatile* addend) { return __sync_sub_and_fetch(addend, 1); }
 
 #endif
 
