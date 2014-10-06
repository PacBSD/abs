--- src/lxdm.c.orig	2013-11-01 13:01:31.000000000 +0000
+++ src/lxdm.c	2014-10-06 05:01:21.595691984 +0000
@@ -27,7 +27,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <string.h>
+#include <strings.h>
 #include <stdarg.h>
 #include <ctype.h>
 #include <stdint.h>
@@ -36,7 +36,7 @@
 #include <fcntl.h>
 #include <pwd.h>
 #include <grp.h>
-#include <shadow.h>
+#include <xorg/shadow.h>
 #include <errno.h>
 #include <signal.h>
 #include <time.h>
@@ -45,7 +45,10 @@
 #include <glib.h>
 #include <glib/gstdio.h>
 
+#if !defined(__FreeBSD__)
 #include <sys/vt.h>
+#endif
+
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 
@@ -1359,7 +1362,7 @@
 {
 	char *cmd;
 	cmd = g_key_file_get_string(config, "cmd", "reboot", 0);
-	if( !cmd ) cmd = g_strdup("reboot");
+	if( !cmd ) cmd = g_strdup("shutdown -r now");
 	g_spawn_command_line_sync("/etc/lxdm/PreReboot",0,0,0,0);
 	g_spawn_command_line_async(cmd,0);
 	g_free(cmd);
