--- src/sna/sna_dri2.c.orig	2014-09-03 04:27:11.000000000 -0400
+++ src/sna/sna_dri2.c	2014-09-16 02:23:52.000000000 -0400
@@ -162,7 +162,7 @@
 
 	bo = NULL;
 	if (info) {
-		struct dri_bo *c;
+		struct dri_bo *c = NULL;
 		list_for_each_entry(c, &info->cache, link) {
 			if (c->bo && c->bo->scanout == 0) {
 				bo = c->bo;
@@ -192,7 +192,7 @@
 
 	if (info && reuse) {
 		bool found = false;
-		struct dri_bo *c;
+		struct dri_bo *c = NULL;
 
 		list_for_each_entry_reverse(c, &info->cache, link) {
 			if (c->bo == NULL) {
