#include "stdlib.h"
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

/**
 * A : Array
 * n : Array size
 * i : Element in the array [1,n], 1 for the first element
 **/
static void maxHeapify(int *A, int n, int i){

  register int l, r, largest, aux;
  
  while(1){
    
    l = i<< 1; // left child
    r = l+1;   // rigth child

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

static void buildMaxHeap(int* A, int n){

  register int i;
  
  for(i=n/2; i>0; i--){
    maxHeapify(A, n, i);
  }
}

void heapSort(int* A, int n){

  register int i, aux;
  
  buildMaxHeap(A, n);
  for(i=n; i>1 ; i--){

    // Exchange A1 with Ai
    aux = A[i-1];
    A[i-1] = A[0];
    A[0] = aux;

    maxHeapify(A, (i-1), 1);
  }
}


/**
 * MERGER SORT
 **/

struct list {
  int value;
  int pos;
  struct list* next;
};

typedef struct list list;

void mergeSort(int*A, int n){

  register int i, j, aux, aux2;
  register list** pList;
  register list* l1, *l2, *auxp;

  pList = (list**)malloc(sizeof(list*)*n);

  for (i=0; i<n; i++){
    pList[i] = (list*)malloc(sizeof(list));
    pList[i]->value = A[i];
    pList[i]->pos = i;
    pList[i]->next = NULL;
  }

  while(i>1){

    for(j=0; j<(i >> 1); j++){
      aux = j << 1;
      aux2 = aux + 1; 
      if(pList[aux]->value <= pList[aux2]->value){
        l1 = pList[aux];
	l2 = pList[aux2];
      }else{
        l1 = pList[aux2];
	l2 = pList[aux];
      }

      pList[j] = l1;

      while(1){
	auxp = l1->next;
        if(auxp == NULL){
          l1->next = l2;
	  break;
	}else if(auxp->value <= l2->value){
          l1 = auxp; 
	}else{
	  l1->next = l2;
	  l1 = l2;
	  l2 = auxp;
	}
      }
    }

    aux = j << 1;
    if(aux  < i){
      pList[j] = pList[i-1];
      i = j+1;
    }
    else{
      i = j;
    }
  }

  l1 = pList[0];
  
  for (i=0; i<n; i++){
    A[i] = l1->value;
    l1 = l1->next; 
  }

}
