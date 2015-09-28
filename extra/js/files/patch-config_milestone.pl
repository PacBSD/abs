--- config/milestone.pl.orig	2015-09-28 21:44:16.876669907 +0100
+++ config/milestone.pl	2015-09-28 21:44:30.009997473 +0100
@@ -56,7 +56,7 @@
 #
 my $milestone = Moz::Milestone::getOfficialMilestone($MILESTONE_FILE);
 
-if (defined(@TEMPLATE_FILE)) {
+if (@TEMPLATE_FILE) {
   my $TFILE;
 
   foreach $TFILE (@TEMPLATE_FILE) {
