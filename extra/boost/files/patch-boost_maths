--- boost/math/tools/config.hpp.orig	2015-05-05 12:32:10 UTC
+++ boost/math/tools/config.hpp
@@ -27,7 +27,9 @@
 
 #include <boost/math/tools/user.hpp>
 
-#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
+#if (defined(__CYGWIN__) || defined(__NetBSD__) \
+   || (defined(__FreeBSD_version) && (__FreeBSD_version < 1002000 \
+        || (__FreeBSD_version >= 1100000 && __FreeBSD_version < 1100078))) \
    || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
    && !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
 #  define BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
