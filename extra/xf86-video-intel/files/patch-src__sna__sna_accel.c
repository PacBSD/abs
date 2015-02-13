--- src/sna/sna_accel.c.orig	2013-11-12 13:13:27.627983913 +0100
+++ src/sna/sna_accel.c	2013-11-12 13:15:33.756971444 +0100
@@ -15391,7 +15391,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == sna->front);
@@ -15547,7 +15547,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 	bool flush = false;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
@@ -15777,7 +15777,8 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = old_front->drawable.pScreen;
-	PixmapDirtyUpdatePtr dirty, safe;
+	PixmapDirtyUpdatePtr dirty = NULL;
+	PixmapDirtyUpdatePtr safe;
 
 	xorg_list_for_each_entry_safe(dirty, safe, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == old_front);
