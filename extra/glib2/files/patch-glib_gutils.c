--- glib/gutils.c.orig	Wed Mar 23 09:55:02 2005
+++ glib/gutils.c	Thu Apr  7 01:06:16 2005
@@ -1929,7 +1929,7 @@ g_get_system_data_dirs (void)
       data_dirs = (gchar *) g_getenv ("XDG_DATA_DIRS");
 
       if (!data_dirs || !data_dirs[0])
-          data_dirs = "/usr/local/share/:/usr/share/";
+          data_dirs = "/usr/share/";
 
       data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
