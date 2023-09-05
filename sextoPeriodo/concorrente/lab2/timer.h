/* Example:  
 *    #include "timer.h"
 *    . . .
 *    double start, finish, elapsed;
 *    . . .
 *    GET_TIME(start);
 *    . . .
 *    Code to be timed
 *    . . .
 *    GET_TIME(finish);
 *    elapsed = finish - start;
 *    printf("The code to be timed took %e seconds\n", elapsed);
*/

#ifndef _CLOCK_TIMER_H
#define _CLOCK_TIMER_H

#include <sys/time.h>
#define BILLION 1000000000L

/* The argument now should be a double (not a pointer to a double) */
#define GET_TIME(now) { \
   struct timespec time; \
   clock_gettime(CLOCK_MONOTONIC, &time); \
   now = time.tv_sec + time.tv_nsec/1000000000.0; \
}
#endif
//now = time.tv_sec + time.tv_nsec/1000000000.0; //seconds
//now = (BILLION * time.tv_sec) + time.tv_nsec; //nanoseconds
