--- aclocal.m4.orig	2013-04-18 23:22:46.000000000 +0200
+++ aclocal.m4	2013-04-29 20:32:30.000000000 +0200
@@ -157,7 +159,7 @@
         i386)
             test -z "[$]2" || eval "[$]2=ArchX86"
             ;;
-        x86_64)
+        x86_64|amd64)
             test -z "[$]2" || eval "[$]2=ArchX86_64"
             ;;
         powerpc)
@@ -185,7 +187,7 @@
 
     checkVendor() {
         case [$]1 in
-        dec|unknown|hp|apple|next|sun|sgi|ibm)
+        dec|unknown|hp|apple|next|sun|sgi|ibm|portbld)
             ;;
         *)
             echo "Unknown vendor [$]1"
@@ -1889,7 +1891,7 @@
   vax)
     $2="vax"
     ;;
-  x86_64)
+  x86_64|amd64)
     $2="x86_64"
     ;;
   *)
