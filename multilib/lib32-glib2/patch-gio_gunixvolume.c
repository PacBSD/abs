--- gio/gunixvolume.c.orig	2014-03-20 03:50:45.000000000 +0000
+++ gio/gunixvolume.c	2014-04-11 14:36:15.185226925 +0100
@@ -356,10 +356,15 @@
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#ifdef __FreeBSD__
+  char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+  argv[2] = unix_volume->device_path;
+#else
+
   const gchar *argv[] = { "eject", NULL, NULL };
 
   argv[1] = unix_volume->device_path;
-
+#endif
   eject_mount_do (volume, cancellable, callback, user_data, argv);
 }
 
