--- src/xfce-taskmanager-linux.c.orig	2014-10-19 18:57:15.000000000 +0000
+++ src/xfce-taskmanager-linux.c	2016-05-03 22:20:11.397891298 +0000
@@ -41,7 +41,7 @@
 	task->checked=FALSE;
 	task->size=0;
 
-	sprintf(line,"/proc/%d/statm",(int)pid);
+	sprintf(line,"/compat/linux/proc/%d/statm",(int)pid);
         fd=open(line,O_RDONLY);
         if(fd==-1) return;
         ret = read(fd,line,255);
@@ -57,7 +57,7 @@
 	task->size = t_size * page_size;
 	task->rss = t_rss * page_size;
 
-	sprintf(line,"/proc/%d/stat",(gint)pid);
+	sprintf(line,"/compat/linux/proc/%d/stat",(gint)pid);
 	fd=open(line,O_RDONLY);
 	if(fd!=-1)
 	{
@@ -98,7 +98,7 @@
 		if(show_full_path)
 		{
 			FILE *fp;
-			sprintf(line,"/proc/%d/cmdline",(int)pid);
+			sprintf(line,"/compat/linux/proc/%d/cmdline",(int)pid);
 			fp=fopen(line,"r");
 			if(fp)
 			{
@@ -124,7 +124,7 @@
 		else if(len>=15)
 		{
 			FILE *fp;
-			sprintf(line,"/proc/%d/cmdline",(int)pid);
+			sprintf(line,"/compat/linux/proc/%d/cmdline",(int)pid);
 			fp=fopen(line,"r");
 			if(fp)
 			{
@@ -192,9 +192,10 @@
     int n;
     int count=0;
 
+#define PAGE_SIZE ( sysconf(_SC_PAGESIZE) )
 
     task_list = g_array_new(FALSE, FALSE, sizeof (struct task));
-    n=scandir("/proc",&namelist,proc_filter,0);
+    n=scandir("/compat/linux/proc",&namelist,proc_filter,0);
     if(n<0) return task_list;
 
     g_array_set_size(task_list,n);
@@ -216,7 +217,7 @@
 
 gboolean get_cpu_usage_from_proc(system_status *sys_stat)
 {
-    const gchar *file_name = "/proc/stat";
+    const gchar *file_name = "/compat/linux/proc/stat";
     FILE *file;
 
     if ( sys_stat->valid_proc_reading == TRUE ) {
@@ -257,7 +258,7 @@
     int reach;
     static int cpu_count;
 
-    file = fopen ("/proc/meminfo", "r");
+    file = fopen ("/compat/linux/proc/meminfo", "r");
     if(!file) return FALSE;
     reach=0;
     while (fgets (buffer, 100, file) != NULL)
