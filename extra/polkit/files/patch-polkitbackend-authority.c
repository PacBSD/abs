--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2015-06-17 18:15:22.158852474 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c	2015-06-17 18:16:13.508854519 +0000
@@ -2113,11 +2113,15 @@
   ret = NULL;
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
+#ifdef __FreeBSD__
+  setnetgrent (name);
+#else
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
       goto out;
     }
+#endif
 
   for (;;)
     {
