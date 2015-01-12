#if __SIZEOF_POINTER__ == 4
#include "config_types-32.h"
#elif __SIZEOF_POINTER__ == 8
#include "config_types-64.h"
#else
#error "Unknown word size"
#endif
