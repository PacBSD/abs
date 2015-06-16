--- update-mime-database.c.orig	2007-07-02 04:00:13.000000000 -0500
+++ update-mime-database.c	2008-01-28 23:42:30.000000000 -0600
@@ -445,7 +446,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+		xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
