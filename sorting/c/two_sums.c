#include "stdlib.h"
#include "stdio.h"
#include <math.h>

typedef struct{
  int value;
  int pos;
} Element;



/**
 * HEAPSORT
 **/

/**
 * A : Array
 * n : Array size
 * i : Element in the array [1,n], 1 for the first element
 **/
static void maxHeapify(Element *A, int n, int i){

  register int l, r, largest;
  register Element aux;
  
  while(1){
    
    l = i << 1;
    r = l + 1;

    if((l <= n) && (A[l-1].value > A[i-1].value)){
      largest = l;
    }else{
      largest = i;
    }

    if((r <= n) && (A[r-1].value > A[largest-1].value)){
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

static void buildMaxHeap(Element* A, int n){

  register int i;
  
  for(i=n/2; i>0; i--){
    maxHeapify(A, n, i);
  }
}

void heapSort(Element* A, int n){

  register int i;
  register Element aux;
  
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum_heapSort(int* nums, int numsSize, int target) {

  int* result;
  int i,j,s;
  Element *A;

  result = (int*)malloc(sizeof(int)*2);
  
  A = (Element*)malloc(sizeof(Element)*numsSize);
  
  for(i=0 ; i<numsSize; i++){
    A[i].pos = i;
    A[i].value = nums[i];
  }

  heapSort(A, numsSize);

  i = 0;
  j = numsSize - 1;
  
  while(1){
    s = A[i].value + A[j].value;
    if(s == target){
      result[0] = A[i].pos;
      result[1] = A[j].pos;
      break;
    }else if(s > target){
      j--;
    }else{
      i++;
    }
  }

  /*
  for(i=0;i<numsSize;i++) {
    printf("%d %d   ", A[i].value, A[i].pos);
  }
  printf("\n");
  */
  
  return result;
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

void mergeSort(list* pList[], int n){

  register int i, j, aux, aux2;
  register list *l1, *l2, *auxp;

  i = n;
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
        if(l1->next == NULL){
          l1->next = l2;
	  break;
	}else if((l1->next)->value <= l2->value){
          l1 = l1->next; 
	}else{
	  auxp = l1->next;
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
  
  for (i=1; i<n; i++){
    pList[i] = l1->next;
    l1 = l1->next; 
  }

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target) {

  int* result;
  register int i,j,s;
  register list **pList;

  result = (int*)malloc(sizeof(int)*2);

  pList = (list**)malloc(sizeof(list*)*numsSize);

  for (i=0; i<numsSize; i++){
    pList[i] = (list*)malloc(sizeof(list));
    pList[i]->value = nums[i];
    pList[i]->pos = i;
    pList[i]->next = NULL;
  }

  mergeSort(pList, numsSize);

  i = 0;
  j = numsSize - 1;
  
  while(1){
    s = pList[i]->value + pList[j]->value;
    if(s == target){
      if(pList[i]->pos <= pList[j]->pos){
        result[0] = pList[i]->pos;
        result[1] = pList[j]->pos;
      }else{
        result[0] = pList[j]->pos;
        result[1] = pList[i]->pos;
      }
      break;
    }else if(s > target){
      j--;
    }else{
      i++;
    }
  }

  /*
  for(i=0;i<numsSize;i++) {
    printf("%d %d   ", A[i].value, A[i].pos);
  }
  printf("\n");
  */
  
  return result;
}

void main(){

  int i;
  int *result;
  //int A[] = {0,4,3,0};
  //int n = 4;
  int A[] = {150,24,79,50,88,345,3};
  int n = 7;
  int target = 200;

  result = twoSum(A, n, target);
 
  
  for(i=0;i<n;i++) printf("%d ", A[i]);
  printf("\n result: %d %d\n", result[0], result[1]);

}
