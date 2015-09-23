diff --git a/src/sna/sna_dri2.c b/src/sna/sna_dri2.c
index 13714fb..044e0d3 100644
--- src/sna/sna_dri2.c.orig
+++ src/sna/sna_dri2.c
@@ -212,7 +212,7 @@ sna_dri2_cache_bo(struct sna *sna,
 		  uint32_t size,
 		  uint32_t flags)
 {
-	struct dri_bo *c;
+	struct dri_bo *c = NULL;
 
 	if (draw == NULL) {
 		DBG(("%s: no draw, releasing handle=%d\n",
@@ -265,7 +265,7 @@ sna_dri2_get_back(struct sna *sna,
 	struct dri2_window *priv = dri2_window((WindowPtr)draw);
 	uint32_t size;
 	struct kgem_bo *bo;
-	struct dri_bo *c;
+	struct dri_bo *c = NULL;
 	uint32_t name;
 	int flags;
 	bool reuse;
@@ -1509,7 +1509,7 @@ sna_dri2_remove_event(WindowPtr win, struct sna_dri2_event *info)
 	priv->chain = info->chain;
 	if (priv->chain == NULL) {
 		while (!list_is_empty(&priv->cache)) {
-			struct dri_bo *c;
+			struct dri_bo *c = NULL;
 
 			c = list_first_entry(&priv->cache, struct dri_bo, link);
 			list_del(&c->link);
@@ -1709,7 +1709,7 @@ void sna_dri2_destroy_window(WindowPtr win)
 	}
 
 	while (!list_is_empty(&priv->cache)) {
-		struct dri_bo *c;
+		struct dri_bo *c = NULL;
 
 		c = list_first_entry(&priv->cache, struct dri_bo, link);
 		list_del(&c->link);
