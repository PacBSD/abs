--- src/print_eth_info.c.orig	2015-09-22 22:37:29.089859779 +0100
+++ src/print_eth_info.c	2015-09-22 22:39:36.874030270 +0100
@@ -21,8 +21,6 @@
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <net/if_media.h>
-#define IFM_TYPE_MATCH(dt, t) \
-    (IFM_TYPE((dt)) == 0 || IFM_TYPE((dt)) == IFM_TYPE((t)))
 
 #define PART_ETHSPEED "E: %s (%s)"
 #endif
@@ -53,19 +51,30 @@
     struct ifmediareq ifm;
     (void)memset(&ifm, 0, sizeof(ifm));
     (void)strncpy(ifm.ifm_name, interface, sizeof(ifm.ifm_name));
-    int ret = ioctl(general_socket, SIOCGIFMEDIA, (caddr_t)&ifm);
+     int ret;
+#ifdef SIOCGIFXMEDIA
+        ret = ioctl(general_socket, SIOCGIFXMEDIA, (caddr_t)&ifm);
+        if (ret < 0)
+#endif
+            ret = ioctl(general_socket, SIOCGIFMEDIA, (caddr_t)&ifm);
+        if (ret < 0)
+            return sprintf(outwalk, "?");
 
     /* Get the description of the media type, partially taken from
      * FreeBSD's ifconfig */
     const struct ifmedia_description *desc;
-    struct ifmedia_description ifm_subtype_descriptions[] =
+    static struct ifmedia_description ifm_subtype_descriptions[] =
         IFM_SUBTYPE_ETHERNET_DESCRIPTIONS;
 
+    if (IFM_TYPE(ifm.ifm_active) != IFM_ETHER)
+        return sprintf(outwalk, "?");
+    if (ifm.ifm_status & IFM_AVALID && !(ifm.ifm_status & IFM_ACTIVE))
+        return sprintf(outwalk, "no carrier");
+
     for (desc = ifm_subtype_descriptions;
          desc->ifmt_string != NULL;
          desc++) {
-        if (IFM_TYPE_MATCH(desc->ifmt_word, ifm.ifm_active) &&
-            IFM_SUBTYPE(desc->ifmt_word) == IFM_SUBTYPE(ifm.ifm_active))
+    if (desc->ifmt_word == IFM_SUBTYPE(ifm.ifm_active))
             break;
     }
     ethspeed = (desc->ifmt_string != NULL ? desc->ifmt_string : "?");
