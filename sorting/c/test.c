#include "stdio.h"
#include "sorting.h"

int main(void){

  int i;
  int A[] = {0,4,3,0};
  int n = 4;

  //printf("test bubblesort:\n");
  //bubbleSort(A, n);
  
  //printf("test heapSort:\n");
  //heapSort(A, n);

  printf("test mergeSort:\n");
  mergeSort(A, n);
  
  for(i=0;i<n;i++) printf("%d ", A[i]);
  printf("\n");
}
