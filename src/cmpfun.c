#include "cmpfun.h"

int cmpfun (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
