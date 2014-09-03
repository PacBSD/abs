#if __SIZEOF_POINTER__ == 4
 #include "curlbuild-32.h"
#elif __SIZEOF_POINTER__ == 8
 #include "curlbuild-64.h"
#else
 #error "Unknown word size"
#endif
