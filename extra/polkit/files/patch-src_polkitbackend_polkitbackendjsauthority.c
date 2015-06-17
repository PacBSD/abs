--- src/polkitbackend/polkitbackendjsauthority.c.orig	2015-06-17 18:18:18.318844129 +0000
+++ src/polkitbackend/polkitbackendjsauthority.c	2015-06-17 18:18:56.409942576 +0000
@@ -1286,7 +1286,9 @@
     _HANDLE_SIG (SIGTTIN);
     _HANDLE_SIG (SIGTTOU);
     _HANDLE_SIG (SIGBUS);
+#ifdef SIGPOLL
     _HANDLE_SIG (SIGPOLL);
+#endif
     _HANDLE_SIG (SIGPROF);
     _HANDLE_SIG (SIGSYS);
     _HANDLE_SIG (SIGTRAP);
