#include "stdio.h"
#include "sorting.h"

int main(void){

  int i;
  int A[] = {4,3,8};
  int n = 3;
  
  printf("test bubblesort:\n");
  bubblesort(n, A);

  for(i=0;i<n;i++) printf("%d ", A[i]);
  printf("\n");
}
