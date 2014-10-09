--- configure.ac.orig	2014-05-17 08:38:43.000000000 +0200
+++ configure.ac	2014-05-18 11:54:55.000000000 +0200
@@ -37,6 +37,7 @@
 DRI3PROTO_REQUIRED=1.0
 PRESENTPROTO_REQUIRED=1.0
 LIBUDEV_REQUIRED=151
+LIBDEVQ_REQUIRED=0.0.2
 GLPROTO_REQUIRED=1.4.14
 LIBOMXIL_BELLAGIO_REQUIRED=0.0
 VDPAU_REQUIRED=0.4.1
@@ -53,7 +54,7 @@
 AM_PROG_CC_C_O
 AM_PROG_AS
 AC_CHECK_PROGS([MAKE], [gmake make])
-AC_CHECK_PROGS([PYTHON2], [python2 python])
+AC_CHECK_PROGS([PYTHON2], [python2.7 python2 python])
 AC_PROG_SED
 AC_PROG_MKDIR_P
 
@@ -152,7 +153,7 @@
 DEFINES=""
 AC_SUBST([DEFINES])
 case "$host_os" in
-linux*|*-gnu*|gnu*)
+linux*|*-gnu*|gnu*|freebsd*)
     DEFINES="$DEFINES -D_GNU_SOURCE -DHAVE_PTHREAD"
     ;;
 solaris*)
@@ -567,7 +568,7 @@
     [enable_dri=yes])
 
 case "$host_os" in
-linux*)
+linux*|freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -818,13 +819,23 @@
 
 case "$host_os" in
 linux*)
-    need_libudev=yes ;;
+    need_libudev=yes
+    need_libdevq=no
+    ;;
+freebsd*)
+    need_libdevq=yes
+    need_libudev=no
+    ;;
 *)
-    need_libudev=no ;;
+    need_libdevq=no
+    need_libudev=no
+    ;;
 esac
 
 PKG_CHECK_MODULES([LIBUDEV], [libudev >= $LIBUDEV_REQUIRED],
                   have_libudev=yes, have_libudev=no)
+PKG_CHECK_MODULES([LIBDEVQ], [libdevq-1.0 >= $LIBDEVQ_REQUIRED],
+                  have_libdevq=yes, have_libdevq=no)
 
 if test "x$enable_dri" = xyes; then
     if test "$enable_static" = yes; then
@@ -913,6 +924,9 @@
 if test "$have_libudev" = yes; then
     DEFINES="$DEFINES -DHAVE_LIBUDEV"
 fi
+if test "$have_libdevq" = yes; then
+    DEFINES="$DEFINES -DHAVE_LIBDEVQ"
+fi
 
 # This is outside the case (above) so that it is invoked even for non-GLX
 # builds.
@@ -1029,6 +1043,23 @@
     *freebsd* | dragonfly* | *netbsd* | openbsd*)
         DEFINES="$DEFINES -DHAVE_PTHREAD -DUSE_EXTERNAL_DXTN_LIB=1"
         DEFINES="$DEFINES -DHAVE_ALIAS"
+dnl not sure about dri3 support, just enable it for now.
+        if test "x$enable_dri3" = xyes; then
+            DEFINES="$DEFINES -DHAVE_DRI3"
+        fi
+
+        if test "x$have_libdevq" != xyes; then
+            AC_MSG_ERROR([libdevq required for building DRI])
+        fi
+
+        case "$host_cpu" in
+        powerpc* | sparc*)
+            # Build only the drivers for cards that exist on PowerPC/sparc
+            if test "x$with_dri_drivers" = "xyes"; then
+                with_dri_drivers="r200 radeon swrast"
+            fi
+            ;;
+        esac
         ;;
     gnu*)
         DEFINES="$DEFINES -DUSE_EXTERNAL_DXTN_LIB=1"
@@ -1204,6 +1235,8 @@
 AM_CONDITIONAL(HAVE_GBM, test "x$enable_gbm" = xyes)
 if test "x$need_libudev" = xyes; then
     GBM_PC_REQ_PRIV="libudev >= $LIBUDEV_REQUIRED"
+elif test "x$need_libdevq" = xyes; then
+    GBM_PC_REQ_PRIV="libdevq >= $LIBDEVQ_REQUIRED"
 else
     GBM_PC_REQ_PRIV=""
 fi
@@ -1662,8 +1695,6 @@
                 CLANG_LIBDIR=${LLVM_LIBDIR}
             fi
             CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-            AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-                [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
         fi
     else
         MESA_LLVM=0
