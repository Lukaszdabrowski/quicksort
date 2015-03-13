#ifndef MEASURE_H_
#define MEASURE_H_

/* INFO: Needed for error_t. */
#include "error_type.h"

/* INFO: Shorten form, more readable for programmer. */
typedef struct timespec time_moment_t;

/* INFO: Computes the period of the time between two time moments. */
error_t period(
	const time_moment_t * const,
	const time_moment_t * const,
	long * const);

/* INFO: Measuring function. */
error_t mesure(long * const);

#endif

