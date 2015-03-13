#ifndef CHECK_H_
#define CHECK_H_

/* INFO: Needed for fprintf. */
#include <stdio.h>

/* INFO: Needed for EXIT_SUCCESS. */
#include <stdlib.h>

/* INFO: Check if error occured. */
#define CHECK_ERROR(fun)			if(fun != EXIT_SUCCESS) { \
							fprintf(stderr, \
								"Error in " \
								"%s:%d\n", \
								__FILE__, \
								__LINE__); \
								exit(1); \
						}

#endif

