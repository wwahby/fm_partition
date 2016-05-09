// System dependent routines
// File: system.cpp / system.cc


#include "system.hpp"


double seconds()
{
#ifdef BSD       // BSD system instead of SYSV
   rusage time;
   getrusage(RUSAGE_SELF,&time);
   return (double)(1.0*time.ru_utime.tv_sec+0.000001*time.ru_utime.tv_usec);
#else
   return double(clock())/CLOCKS_PER_SEC;
#endif
}
