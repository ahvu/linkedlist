
#ifndef LINKED_LIST_DEBUG_H_
#define LINKED_LIST_DEBUG_H_

#define LINKED_LIST_DEBUG


#ifndef LINKED_LIST_DEBUG
// compile with all debug messages removed
#define LIST_DEBUG(M, ...)
#else
#include <iostream>
#include <stdio.h>
#include <string.h>
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LIST_DEBUG(M, ...) printf("Function:%s\r\n-D-   " M "\r\n", __func__, ##__VA_ARGS__)
#endif

#endif
