--- gyp/common.gypi.orig	2013-07-17 11:38:04.000000000 +0900
+++ gyp/common.gypi	2013-07-19 22:51:13.000000000 +0900
@@ -749,6 +749,7 @@
       ['OS=="linux"', {
         'defines': [
           'OS_LINUX',
+          'OS_FREEBSD',
         ],
         'cflags': [
           '<@(warning_cflags)',
