--- src/camera.h.old	2013-07-28 15:09:45.722687634 +0200
+++ src/camera.h	2013-07-28 15:16:37.383691874 +0200
@@ -37,7 +37,9 @@
     #include <sys/mman.h>
     #include <sys/ioctl.h>
 
+#ifndef __FreeBSD__
     #include <asm/types.h>          /* for videodev2.h */
+#endif
 
     #include <linux/videodev2.h>
 #endif
