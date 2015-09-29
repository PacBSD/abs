--- src/modules/oss/module-oss.c.orig	2014-01-23 19:57:55.000000000 +0100
+++ src/modules/oss/module-oss.c	2014-03-22 10:59:05.000000000 +0100
@@ -1229,10 +1229,14 @@ int pa__init(pa_module*m) {
         use_mmap = false;
     }
 
+#ifndef __FreeBSD__
+/* Disable mmap. The OSS on FreeBSD doesn't support read & write on 
+   the same socket */
     if (use_mmap && mode == O_WRONLY) {
         pa_log_info("Device opened for playback only, cannot do memory mapping, falling back to UNIX write() mode.");
         use_mmap = false;
     }
+#endif
 
     if (pa_oss_get_hw_description(dev, hwdesc, sizeof(hwdesc)) >= 0)
         pa_log_info("Hardware name is '%s'.", hwdesc);
