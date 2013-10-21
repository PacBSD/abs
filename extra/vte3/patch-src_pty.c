--- src/pty.c.orig	2012-05-23 22:43:04.000000000 +0200
+++ src/pty.c	2012-07-20 14:36:58.337340000 +0200
@@ -837,7 +837,11 @@
 _vte_pty_getpt(GError **error)
 {
 	int fd, flags, rv;
-#ifdef HAVE_GETPT
+
+#ifdef HAVE_POSIX_OPENPT
+	/* Call the system's function for allocating a pty. */
+	fd = posix_openpt(O_RDWR | O_NOCTTY);
+#elif HAVE_GETPT
 	/* Call the system's function for allocating a pty. */
 	fd = getpt();
 #else
