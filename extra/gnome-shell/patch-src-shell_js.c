--- src/shell-js.c.orig	2014-03-22 15:19:32.976063919 +0000
+++ src/shell-js.c	2014-03-22 15:20:11.285590075 +0000
@@ -55,8 +55,7 @@
                          &target_object))
     {
       char *message;
-      gjs_log_exception(context,
-                        &message);
+      gjs_log_exception(context);
       g_set_error(error,
                   G_IO_ERROR,
                   G_IO_ERROR_FAILED,
