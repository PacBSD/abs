--- src/torrent/connection_manager.h.orig	2013-08-02 23:49:20.978696421 +0200
+++ src/torrent/connection_manager.h	2013-08-02 23:48:23.925698404 +0200
@@ -40,6 +40,7 @@
 #ifndef LIBTORRENT_CONNECTION_MANAGER_H
 #define LIBTORRENT_CONNECTION_MANAGER_H

+#include <inttypes.h>
 #include <list>
 #include <arpa/inet.h>
 #include <netinet/in.h>
