--- src/sna/sna_accel.c.orig	2015-09-23 11:11:40.046461816 +0100
+++ src/sna/sna_accel.c	2015-09-23 11:14:56.126452723 +0100
@@ -17379,7 +17379,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = to_screen_from_sna(sna);
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == sna->front);
@@ -17527,7 +17527,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = to_screen_from_sna(sna);
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		RegionRec region, *damage;
@@ -17790,7 +17790,8 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = old_front->drawable.pScreen;
-	PixmapDirtyUpdatePtr dirty, safe;
+	PixmapDirtyUpdatePtr dirty = NULL;
+	PixmapDirtyUpdatePtr safe;
 
 	xorg_list_for_each_entry_safe(dirty, safe, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == old_front);
