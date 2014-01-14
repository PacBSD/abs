--- lib/Factories/AbstractMain.vala.orig	2013-11-15 15:13:35.000000000 +0000
+++ lib/Factories/Abstractmain.vala	2014-01-10 18:44:56.151183565 +0000
@@ -163,7 +163,11 @@
 		protected virtual void initialize_program ()
 		{
 			// set program name
-			prctl (15, exec_name);
+			 #if LINUX
+			              prctl (15, exec_name);
+		       #elif FREEBSD
+		                      setproctitle (exec_name);
+		       #endif
 			Environment.set_prgname (exec_name);
 			
 			Posix.signal(Posix.SIGINT, sig_handler);
