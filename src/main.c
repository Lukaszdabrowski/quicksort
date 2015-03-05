#include <stdio.h>
#include <stdlib.h>
#include "cmpfun.h"

int values[] = { 88, 56, 100, 2, 25 };

int main()
{
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), cmpfun);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }
   printf("\n");
  
  return(0);
}
