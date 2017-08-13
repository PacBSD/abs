From f44157c809d280e2a0ce87fb078fc4b278d24a67 Mon Sep 17 00:00:00 2001
From: Akira TAGOH <akira@tagoh.org>
Date: Thu, 10 Apr 2014 10:27:55 +0000
Subject: Fix fc-cache fail with -r

Do not unlink the cache even if --really-force is given.
because re-scanning process expects the cache exists.

https://bugs.freedesktop.org/show_bug.cgi?id=77252
---
diff --git a/fc-cache/fc-cache.c b/fc-cache/fc-cache.c
index 99e0e9f..90ebad3 100644
--- fc-cache/fc-cache.c
+++ fc-cache/fc-cache.c
@@ -388,7 +388,7 @@ main (int argc, char **argv)
     list = FcStrListCreate (updateDirs);
     if (list)
     {
-	ret += scanDirs (list, config, FcTrue, really_force, verbose, FcFalse, &changed, NULL);
+	ret += scanDirs (list, config, FcTrue, FcFalse, verbose, FcFalse, &changed, NULL);
 	FcStrListDone (list);
     }
     FcStrSetDestroy (updateDirs);
--
cgit v0.9.0.2-2-gbebe
