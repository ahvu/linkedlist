
#ifndef LINKEDLIST_DEBUG_H_
#define LINKEDLIST_DEBUG_H_

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LINKED_LIST_DEBUG
#ifndef LINKED_LIST_DEBUG
// compile with all debug messages removed
#define LIST_DEBUG(M, ...)
#else
#define LIST_DEBUG(M, ...) printf("Function:%s\r\n-D-   " M "\r\n", __func__, ##__VA_ARGS__)
#endif

#endif
