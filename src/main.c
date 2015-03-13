#include<stdio.h>
#include<time.h>
#include<stdint.h>

void quicksort(int [10],int,int);

int main(){
  int x[20],size,i;

  printf("Podaj ilosc elementow: ");
  scanf("%d",&size);

  printf("Wprowadz %d liczb: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  quicksort(x,0,size-1);

  printf("Posortowane elementy: ");
  for(i=0;i<size;i++)
    printf(" %d",x[i]);

  return 0;
}

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

int main(int argc, char **argv)
{
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);
         
         clock_gettime(CLOCK_MONOTONIC, &end);
         uint64_t timeElapsed = timespecDiff(&end, &start);
        }
    }
}


int timer(){
    clock_t start = clock();

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
}
