--- base/base.gyp.orig	2013-03-29 13:33:43.000000000 +0900
+++ base/base.gyp	2013-04-23 23:49:53.000000000 +0900
@@ -265,20 +265,20 @@
         ['OS=="linux" and target_platform!="Android" and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
           'cflags': [
-            '<!@(<(pkg_config_command) --cflags-only-other openssl)',
+            ' ',
           ],
           'defines': [
             'HAVE_OPENSSL=1',
           ],
           'include_dirs': [
-            '<!@(<(pkg_config_command) --cflags-only-I openssl)',
+            ' ',
           ],
           'link_settings': {
             'ldflags': [
-              '<!@(<(pkg_config_command) --libs-only-L openssl)',
+              ' ',
             ],
             'libraries': [
-              '<!@(<(pkg_config_command) --libs-only-l openssl)',
+              '-lssl -lcrypto',
             ],
           },
         }],
