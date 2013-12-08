--- Tools/DumpRenderTree/gtk/DumpRenderTree.cpp.orig	2013-09-10 13:19:16.000000000 +0200
+++ Tools/DumpRenderTree/gtk/DumpRenderTree.cpp	2013-09-10 13:19:47.000000000 +0200
@@ -48,6 +48,7 @@
 #include "WorkQueueItem.h"
 #include <JavaScriptCore/JavaScript.h>
 #include <cassert>
+#include <clocale>
 #include <cstdlib>
 #include <cstring>
 #include <getopt.h>
 
patch-Tools_DumpRenderTree_gtk_ImageDiff.cpp:
--- Tools/DumpRenderTree/gtk/ImageDiff.cpp.orig	2013-09-10 13:16:33.000000000 +0200
+++ Tools/DumpRenderTree/gtk/ImageDiff.cpp	2013-09-10 13:16:39.000000000 +0200
@@ -30,6 +30,7 @@
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
+#include <cstdlib>
 #include <cstring>
 #include <gdk/gdk.h>
