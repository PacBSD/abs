--- src/lxdm.h.orig	2014-10-06 03:37:34.026455252 +0000
+++ src/lxdm.h	2014-10-06 03:42:06.442089433 +0000
@@ -59,6 +59,15 @@
 GSList *do_scan_xsessions(void);
 void free_xsessions(GSList *);
 
+struct vt_stat {
+   unsigned short v_active;   /* active vt */
+   unsigned short v_signal;   /* signal to send */
+   unsigned short v_state;      /* vt bitmask */
+};
+
+#define VT_GETSTATE   0x5603
+#define VT_ACTIVATE   0x5606
+
 G_END_DECLS
 
 #endif/*_LXDM_H_*/
