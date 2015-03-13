/* INFO: Needed for printf. */
#include <stdio.h>

/* INFO: Needed for strcmp. */
#include <string.h>

/* INFO: Needed for CHECK_ERROR. */
#include "check.h"

/* INFO: Needed for CONFIG_NANOSECONDS_PER_SECOND. */
#include "config.h"

/* INFO: Needed for error_t. */
#include "error_type.h"

/* INFO: Needed for test functionality. */
#include "measure.h"

/* INFO: Check if program is used properly. */
static error_t prerequisites(const int);

static error_t convert(
	const int,
	const char * const [],
	int ** const);

/* INFO: */
/* TODO: ***************************************************/
/* TODO: Move this function to quicksort.h and quicksort.c */
/* TODO: ***************************************************/
/*
void quicksort(int x[10], int first, int last) {
	int pivot = 0;
	int j = 0;
	int temp = 0;
	int i;

	if(first < last){
		pivot = first;
		i = first;
		j = last;

		while(i<j){
			while((x[i] <= x[pivot]) && (i < last)) {
				i++;
			}

			while(x[j] > x[pivot]) {
				j--;
			}

			if(i < j) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort(x, first, (j - 1));
		quicksort(x, (j + 1), last);

	}
}
*/

/* INFO: Check if program is used properly. */
static error_t prerequisites(const int inpArgumentCount) {
	if(inpArgumentCount < 3) {
		printf("Quicksort profiler\n");
		printf("   usage: ./profiler integer_0 integer_1 [integer_2] ...\n");
		printf("   example: ./profiler 5 6 2 1\n");

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static error_t convert(
		const int inpArgumentCount,
		const char * const inpArgumentArray[],
		int ** const localNumberArray) {
	int localIndex = 0;
	int localIndexInArray = 0;
	int localNumber = 0;
	int localNumberCount = 0;
	const char * localNumberString = NULL;

	/* INFO: Number count is one less than argument count. */
	localNumberCount = (inpArgumentCount - 1);

	(* localNumberArray) = (int *)malloc(localNumberCount * sizeof(int));

	for(localIndex = 1; localIndex < inpArgumentCount; ++localIndex) {
		localNumberString = inpArgumentArray[localIndex];
		localNumber = atoi(localNumberString);

		if((localNumber == 0) && (strcmp(localNumberString, "0"))) {
			printf(" * argument no %d (%s) is not a number\n",
				localIndex, localNumberString);

			return EXIT_FAILURE;
		}

		localIndexInArray = localIndex - 1;

		(* localNumberArray)[localIndexInArray] = localNumber;
	}

	return EXIT_SUCCESS;
}

/* INFO: Program entrance. */
error_t main(
		const int inpArgumentCount,
		const char * const inpArgumentArray[]){
	long localTimePeriod = 0;
	int * localNumberArray = NULL;

	/* INFO: Check prerequisites. */
	CHECK_ERROR(prerequisites(inpArgumentCount));

	/* INFO: Convert argument strings into neturals. */
	CHECK_ERROR(convert(inpArgumentCount, inpArgumentArray,
		(& localNumberArray)));

	/* TODO: *****************************************/
	/* TODO: Here you have your integers (int type). */
	/* TODO: *****************************************/

	/* INFO: Measure sorting time. */
	/* TODO: *************************************************************/
	/* TODO: Pass your array pointer and array size to measure function. */
	/* TODO: *************************************************************/
	CHECK_ERROR(mesure(& localTimePeriod));

	/* INFO: Show the measurement value to the user. */
	printf("Sorting time: %lu (ns)\n", localTimePeriod);

	if(localNumberArray != NULL) {
		free(localNumberArray);
	}

	return EXIT_SUCCESS;
}

