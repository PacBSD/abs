--- rsvg-base.c.orig	2013-10-19 15:39:10.026969414 +0200
+++ rsvg-base.c	2013-10-19 15:39:54.233634406 +0200
@@ -2191,7 +2191,7 @@
     g_object_unref (base);
 
     /* FIXME portability */
-    cdir = canonicalize_file_name (dir);
+    cdir = realpath (dir, NULL);
     g_free (dir);
     if (cdir == NULL)
         goto deny;
@@ -2201,7 +2201,7 @@
         goto deny;
 
     /* FIXME portability */
-    cpath = canonicalize_file_name (path);
+    cpath = realpath (path, NULL);
     g_free (path);
 
     if (cpath == NULL)
