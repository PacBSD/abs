--- gdl/gdl-dock-bar.c
+++ gdl/gdl-dock-bar.c
@@ -484,7 +484,7 @@ GdlDockBarStyle gdl_dock_bar_get_style(GdlDockBar* dockbar)
 {
     GdlDockBarStyle style;
 
-    g_return_if_fail (GDL_IS_DOCK_BAR (dockbar));
+    g_return_val_if_fail (GDL_IS_DOCK_BAR (dockbar), 0);
 
     g_object_get(G_OBJECT(dockbar), "dockbar-style", &style, NULL);
