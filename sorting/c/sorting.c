
#include "stdio.h"


void bubblesort(int n, int* array){
  int newn, i, temp;
  
  while(n > 1){
    newn = 0;
    for(i=1; i<n; i++){
      if(array[i-1]>array[i]){
        temp = array[i-1];
	array[i-1] = array[i];
	array[i] = temp;
	newn = i;
      }
    }
    n = newn;
  }
}
