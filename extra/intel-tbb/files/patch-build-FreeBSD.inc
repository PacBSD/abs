--- build/FreeBSD.inc.orig	2012-09-03 13:10:45.423760088 -0400
+++ build/FreeBSD.inc	2012-09-03 13:13:15.765760027 -0400
@@ -54,7 +54,7 @@
 MD?=mkdir -p
 NUL= /dev/null
 SLASH=/
-MAKE_VERSIONS=sh $(tbb_root)/build/version_info_linux.sh $(VERSION_FLAGS) >version_string.ver
+MAKE_VERSIONS=sh $(tbb_root)/build/version_info_FreeBSD.sh $(VERSION_FLAGS) >version_string.ver
 MAKE_TBBVARS=sh $(tbb_root)/build/generate_tbbvars.sh
 
 ifdef LD_LIBRARY_PATH
