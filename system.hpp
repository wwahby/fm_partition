// System dependent definitions and functions
// File: system.hpp

#ifndef SystemIncluded
#define SystemIncluded

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>     // for seconds()
#ifdef BSD
#include <sys/time.h>
#include <sys/resource.h>
#endif


double seconds();

#endif

