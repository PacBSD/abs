--- src/session.c.orig	2013-10-15 04:53:40.068687987 +0200
+++ src/session.c	2013-10-15 04:55:30.905350370 +0200
@@ -56,7 +56,7 @@
 
     char **groups = session_get_groups();
     if (groups) {
-        int i=1;
+        int i=0;
         while (groups[i]) {
             group = groups[i];
             mark = false;
@@ -91,7 +91,7 @@
     char **groups = session_get_groups();
     if (groups) 
     {
-        int i=1;
+        int i=0;
         group = g_strconcat(groupname,  "\n", NULL);
         int l = strlen(group);
         while(groups[i]) 
