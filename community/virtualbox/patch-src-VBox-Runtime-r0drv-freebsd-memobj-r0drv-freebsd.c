From Alan L. Cox on FreeBSD-current:

    I just glanced at the virtualbox code for a couple minutes.  For
    FreeBSD 9 and 10, these lock acquires are completely unnecessary, and
    have been since FreeBSD 9.0.  Just delete them.  They may be equally
    unnecessary under FreeBSD 8, but I didn't look carefully enough to
    answer that question.

[1] http://lists.freebsd.org/pipermail/freebsd-current/2012-November/037963.html
---
 src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c | 9 +++++++++
 1 file changed, 9 insertions(+)

diff --git a/src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c b/src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
index 5c90cf3..1176b51 100644
--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c
@@ -263,11 +268,15 @@ static int rtR0MemObjFreeBSDPhysAllocHelper(vm_object_t pObject, u_long cPages,
             while (iPage-- > 0)
             {
                 pPage = vm_page_lookup(pObject, iPage);
+#if __FreeBSD_version < 900000
                 vm_page_lock_queues();
+#endif
                 if (fWire)
                     vm_page_unwire(pPage, 0);
                 vm_page_free(pPage);
+#if __FreeBSD_version < 900000
                 vm_page_unlock_queues();
+#endif
             }
             VM_OBJECT_UNLOCK(pObject);
             return rcNoMem;
-- 
1.7.11.5

--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2014-01-12 17:35:25.611431818 +0000
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.new	2014-01-12 18:02:33.012990977 +0000
@@ -168,14 +168,19 @@
             VM_OBJECT_LOCK(pMemFreeBSD->pObject);
 #endif
             vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
-            vm_page_lock_queues();
+#if __FreeBSD_version < 900000    
+	vm_page_lock_queues();
+#endif
             for (vm_page_t pPage = vm_page_find_least(pMemFreeBSD->pObject, 0);
                  pPage != NULL;
                  pPage = vm_page_next(pPage))
             {
                 vm_page_unwire(pPage, 0);
             }
-            vm_page_unlock_queues();
+#if __FreeBSD_version < 900000
+	vm_page_unlock_queues();
+#endif
+
 #if __FreeBSD_version >= 1000030
             VM_OBJECT_WUNLOCK(pMemFreeBSD->pObject);
 #else
