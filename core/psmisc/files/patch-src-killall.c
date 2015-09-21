--- src/killall.c.orig	2011-06-20 04:43:24.000000000 -0700
+++ src/killall.c	2011-08-06 21:48:35.014330713 -0700
@@ -36,6 +36,8 @@
 #include <dirent.h>
 #include <signal.h>
 #include <errno.h>
+#include <limits.h>
+#include <locale.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <getopt.h>
@@ -87,40 +89,35 @@
            ignore_case = 0, pidof;
 static long younger_than = 0, older_than = 0;
 
+ /*
+  * This is based on the implementation from 21.5, as the one in 21.6
+  * and newer uses Linux specific functions getline() and rpmatch()
+  */
 static int
 ask (char *name, pid_t pid, const int signal)
 {
-  int res;
-  size_t len;
-  char *line;
-
-  line = NULL;
-  len = 0;
-
-  do {
-    if (signal == SIGTERM)
-        printf (_("Kill %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
-	        pid);
-    else
-        printf (_("Signal %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
-	        pid);
-
-    fflush (stdout);
+  int ch, c;
 
-    if (getline (&line, &len, stdin) < 0)
-      return 0;
-    /* Check for default */
-    if (line[0] == '\n') {
-      free(line);
-      return 0;
-    }
-    res = rpmatch(line);
-    if (res >= 0) {
-      free(line);
-      return res;
+  do
+    {
+      if (signal == SIGTERM)
+          printf (_("Kill %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
+                  pid);
+      else
+          printf (_("Signal %s(%s%d) ? (y/N) "), name, process_group ? "pgid " : "",
+                  pid);
+      fflush (stdout);
+      do
+	if ((ch = getchar ()) == EOF)
+	  exit (0);
+      while (ch == '\n' || ch == '\t' || ch == ' ');
+      do
+	if ((c = getchar ()) == EOF)
+	  exit (0);
+      while (c != '\n');
     }
-  } while(1);
-  /* Never should get here */
+  while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N');
+  return ch == 'y' || ch == 'Y';
 }
 
 static double
@@ -197,7 +194,7 @@
 	
 	while (fgets(buf, sizeof buf, f))
 	{
-		if (sscanf (buf, "Uid:\t%d", &puid))
+		if (sscanf (buf, "%*s %*d %*d %*d %*d %*s %*s %*s %*s %*s %*s %*s %d", &puid))
 		{
 			re = uid==puid;
 			break;
@@ -360,7 +357,7 @@
         }
 #endif /*WITH_SELINUX*/
       /* load process name */
-      if (asprintf (&path, PROC_BASE "/%d/stat", pid_table[i]) < 0)
+      if (asprintf (&path, PROC_BASE "/%d/status", pid_table[i]) < 0)
 	continue;
       if (!(file = fopen (path, "r"))) 
 	{
@@ -368,7 +365,7 @@
 	  continue;
 	}
       free (path);
-      okay = fscanf (file, "%*d (%15[^)]", comm) == 1;
+      okay = fscanf (file, "%s", comm) == 1;
       if (!okay) {
 	fclose(file);
 	continue;
@@ -499,7 +437,7 @@
 	        {
 		  int ok = 1;
 
-	          if (asprintf (&path, PROC_BASE "/%d/exe", pid_table[i]) < 0)
+	          if (asprintf (&path, PROC_BASE "/%d/file", pid_table[i]) < 0)
 		    continue;
 
 	          if (stat (path, &st) < 0) 
@@ -693,7 +631,7 @@
   struct stat isproc;
   pid_t pid = getpid();
 
-  snprintf(filename, sizeof(filename), PROC_BASE"/%d/stat", (int) pid);
+  snprintf(filename, sizeof(filename), PROC_BASE"/%d/status", (int) pid);
   return stat(filename, &isproc) == 0;
 }
 
