--- vapi/compat.vapi.orig	2013-11-15 15:13:29.000000000 +0000
+++ vapi/compat.vapi	2014-01-10 18:43:31.118189428 +0000
@@ -25,8 +25,13 @@
 	[CCode (cheader_filename = "gtk/gtk.h", cname = "gtk_widget_shape_combine_region")]
 	public void gtk_widget_shape_combine_region (Gtk.Widget widget, Cairo.Region? region);
 #endif
+#if LINUX
 	[CCode (cheader_filename = "sys/prctl.h", cname = "prctl", sentinel = "")]
 	public int prctl (int option, ...);
+#elif FREEBSD
+        [CCode (cheader_filename = "unistd.h", cname = "setproctitle")]
+        protected extern static void setproctitle (const char *fmt);
+#endif
 }
 
 [CCode (cheader_filename = "glib.h")]
