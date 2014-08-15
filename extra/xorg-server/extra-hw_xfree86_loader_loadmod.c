--- hw/xfree86/loader/loadmod.c.orig	2013-06-21 15:54:25.000000000 +0200
+++ hw/xfree86/loader/loadmod.c	2013-06-21 15:55:09.000000000 +0200
@@ -490,7 +490,7 @@
     char **elem;
     const char **subdirs;
     const char **s;
-    PatternPtr patterns;
+    PatternPtr patterns = NULL;
     PatternPtr p;
     DIR *d;
     struct dirent *dp;
