#include <time.h>

#include "check.h"
#include "measure.h"
#include "config.h"

/* INFO: Computes the period of the time between two time moments. */
error_t period(
		const time_moment_t * const inpTimeMomentA,
		const time_moment_t * const inpTimeMomentB,
		long * const inpTimePeriod) {
	long localTimeMomentNsA = 0;
	long localTimeMomentNsB = 0;
	long localTimePeriod = 0;

	/* INFO: Convert seconds to nanoseconds. */
	localTimeMomentNsA =
		(inpTimeMomentA->tv_sec * CONFIG_NANOSECONDS_PER_SECOND);
	localTimeMomentNsB =
		(inpTimeMomentB->tv_sec * CONFIG_NANOSECONDS_PER_SECOND);

	/* INFO: Add nanoseconds infromation. */
	localTimeMomentNsA += inpTimeMomentA->tv_nsec;
	localTimeMomentNsB += inpTimeMomentB->tv_nsec;

	/* INFO: Compute the difference. */
	localTimePeriod = (localTimeMomentNsA - localTimeMomentNsB);

	/* INFO: If the period equals to zero - there is some problem. */
	if(localTimePeriod == 0) {
		return EXIT_FAILURE;
	}

	(* inpTimePeriod) = localTimePeriod;

	/* INFO: Computed difference equals to time period. */
	return EXIT_SUCCESS;
}

/* INFO: Measuring function. */
error_t mesure(long * const inpMeasureBuffer) {
	time_moment_t localBeginTime = {0, 0};
	time_moment_t localEndTime = {0, 0};
	long localTimePeriod = 0;

	/* INFO: Catch the time moment. Save the result in localBeginTime. */
	clock_gettime(CLOCK_MONOTONIC, (& localBeginTime));

	/**************************************************************/
	/* INFO: Begin of the code that I am interested in measuring. */
	/**************************************************************/
	/* TODO: Remove sleep function and use your own. Sleep is an example! */
	sleep(1);
	/************************************************************/
	/* INFO: End of the code that I am interested in measuring. */
	/************************************************************/

	/* INFO: Catch the time moment. Save the result in localEndTime. */
	clock_gettime(CLOCK_MONOTONIC, (& localEndTime));

	/* INFO: Compute time period with dedicated function. */
	CHECK_ERROR(period((& localEndTime), (& localBeginTime),
		(& localTimePeriod)));

	/* INFO: If no problems detected, save the value to given buffer. */
	(* inpMeasureBuffer) = localTimePeriod;

	return EXIT_SUCCESS;
}

