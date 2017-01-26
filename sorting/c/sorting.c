
#include "stdio.h"
#include <math.h>

void bubbleSort(int* A, int n){
  int newn, i, temp;
  
  while(n > 1){
    newn = 0;
    for(i=1; i<n; i++){
      if(A[i-1]>A[i]){
        temp = A[i-1];
	A[i-1] = A[i];
	A[i] = temp;
	newn = i;
      }
    }
    n = newn;
  }
}


/**
 * HEAPSORT
 **/

int leftChildPos(int i){
  return (2*i);
}

static inline int rightChildPos(int i){
  return (2*i + 1);
}

/**
 * A : Array
 * n : Array size
 * i : Element in the array [1,n], 1 for the first element
 **/
void maxHeapify(int *A, int n, int i){

  int l, r, largest, aux;
  
  while(1){
    
    l = leftChildPos(i);
    r = rightChildPos(i);

    if((l <= n) && (A[l-1] > A[i-1])){
      largest = l;
    }else{
      largest = i;
    }

    if((r <= n) && (A[r-1] > A[largest-1])){
      largest = r;
    }

    if(largest != i){
      aux = A[i-1];
      A[i-1] = A[largest-1];
      A[largest-1] = aux;
      i = largest;
      
    }else{ // Already max heap
      break;
    }
  }
}

void buildMaxHeap(int* A, int n){

  int i;
  
  for(i=n/2; i>0; i--){
    maxHeapify(A, n, i);
  }
}

void heapSort(int* A, int n){

  int i, aux;
  
  buildMaxHeap(A, n);
  for(i=n; i>1 ; i--){

    // Exchange A1 with Ai
    aux = A[i-1];
    A[i-1] = A[0];
    A[0] = aux;

    maxHeapify(A, (i-1), 1);
  }
}
