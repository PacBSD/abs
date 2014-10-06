--- src/lxcom.c.orig	2013-10-04 07:40:08.000000000 +0000
+++ src/lxcom.c	2014-10-06 03:36:07.535502526 +0000
@@ -16,10 +16,18 @@
 #if defined(__sun)
 #include <ucred.h>
 #include <sys/filio.h>
-#elif !defined(linux) && !defined(__NetBSD__)
+#elif !defined(linux) && !defined(BSD)
 #include <sys/ucred.h>
 #endif
 
+#if defined(__unix__) || defined(unix)
+#include <sys/param.h>
+#endif
+
+#if !defined(_WANT_UCRED)
+	#define _WANT_UCRED
+#endif
+
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/ioctl.h>
@@ -39,7 +47,7 @@
 #    define LXDM_PEER_UID(c)   ucred_geteuid(c)
 #    define LXDM_PEER_GID(c)   ucred_getegid(c)
 #    define LXDM_PEER_PID(c)   ucred_getpid(c)
-#  elif !defined(__NetBSD__)
+#  elif !defined(BSD)
 #    define LXDM_PEER_UID(c)   ((c)->cr_uid)
 #    define LXDM_PEER_GID(c)   ((c)->cr_groups[0])
 #    define LXDM_PEER_PID -1
@@ -54,7 +62,7 @@
 #  define LXDM_PEER_PID(c)   ((c)->pid)
 #endif
 
-#if defined(__NetBSD__)
+#if defined(BSD) || defined (FreeBSD)
 typedef struct sockcred LXDM_CRED;
 #elif defined(__sun)
 typedef ucred_t LXDM_CRED;
@@ -62,6 +70,10 @@
 typedef struct ucred LXDM_CRED;
 #endif
 
+#if !defined(SO_PASSCRED)
+	#define SO_PASSCRED 16
+#endif
+
 #include <glib.h>
 #include "lxcom.h"
 
@@ -136,22 +148,22 @@
 			int argc;
 			char **argv;
 			GString *res;
-
-			#if defined(__sun)
-			size = ucred_size();
-			#elif defined(__NetBSD__)
-			if (cmptr->cmsg_len < SOCKCREDSIZE(0)) break;
-			size = SOCKCREDSIZE(((cred *)CMSG_DATA(cmptr))->sc_ngroups);
+			#if defined(__FreeBSD__)
+			size = SOCKCREDSIZE(((struct sockcred *)CMSG_DATA(cmptr))->sc_ngroups);
 			#else
-			size = sizeof(LXDM_CRED);
-			#endif
+			size = SOCKCREDSIZE(((cred *)CMSG_DATA(cmptr))->sc_ngroups);
+			#endif /* __FreeBSD__ */
 			if (cmptr->cmsg_len != CMSG_LEN(size)) break;
 			if (cmptr->cmsg_level != SOL_SOCKET) break;
 			if (cmptr->cmsg_type != SCM_CREDS) break;
 			c=(LXDM_CRED*)CMSG_DATA(cmptr);
 			if(g_shell_parse_argv(buf,&argc,&argv,NULL))
 			{
+				#if defined(__FreeBSD__)
+				res=((LXComFunc)callback)(user_data,LXDM_PEER_UID(c),LXDM_PEER_PID,argc,argv);
+				#else
 				res=((LXComFunc)callback)(user_data,LXDM_PEER_UID(c),LXDM_PEER_PID(c),argc,argv);
+				#endif /* __FreeBSD__ */
 				g_strfreev(argv);
 				if(res)
 				{
@@ -316,7 +328,7 @@
 {
 	struct iovec iov[1] ={{(void*)buf,count,}};
 	struct msghdr msg = { 0, 0, iov, 1, 0, 0, 0 };
-#if !defined(linux) && !defined(__NetBSD__)
+#if !defined(linux) && !defined(BSD)
 
 #if defined(__sun)
 	int size = ucred_size();
