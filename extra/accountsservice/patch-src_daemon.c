--- src/daemon.c.orig	2014-03-20 18:16:56.000000000 +0000
+++ src/daemon.c	2014-04-14 17:28:10.636486384 +0100
@@ -892,21 +896,19 @@
 
         sys_log (context, "create user '%s'", cd->user_name);
 
-        argv[0] = "/usr/sbin/useradd";
-        argv[1] = "-m";
-        argv[2] = "-c";
-        argv[3] = cd->real_name;
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "useradd";
+        argv[3] = cd->user_name;
+        argv[4] = "-m";
+        argv[5] = "-c";
+        argv[6] = cd->real_name;
         if (cd->account_type == ACCOUNT_TYPE_ADMINISTRATOR) {
-                argv[4] = "-G";
-                argv[5] = ADMIN_GROUP;
-                argv[6] = "--";
-                argv[7] = cd->user_name;
-                argv[8] = NULL;
+                argv[7] = "-G";
+                argv[8] = "Wheel";
+                argv[9] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
-                argv[6] = NULL;
+                argv[7] = NULL;
         }
         else {
                 throw_error (context, ERROR_FAILED, "Don't know how to add user of type %d", cd->account_type);
@@ -1111,19 +1113,11 @@
         g_remove (filename);
         g_free (filename);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[0] = "/usr/sbin/pw";
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
-        }
-        else {
-                argv[1] = "-f";
-                argv[2] = "--";
-                argv[3] = pwent->pw_name;
-                argv[4] = NULL;
+                argv[1] = "userdel";
+                argv[2] = pwent->pw_name;
+                argv[3] = NULL;
         }
 
         error = NULL;
