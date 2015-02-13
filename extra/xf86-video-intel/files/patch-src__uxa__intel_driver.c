--- src/uxa/intel_driver.c.orig	2013-11-12 13:16:42.358972796 +0100
+++ src/uxa/intel_driver.c	2013-11-12 13:16:57.382966332 +0100
@@ -727,7 +727,7 @@
 intel_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 	    return;
