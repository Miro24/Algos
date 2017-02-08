/**
Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 */

#include "macros.h"

double medianOfSortedArrays(int* array1, int array1Size, int* array2, int array2Size) {
  
  register int *aux, i, j, l, r, mediaSize;
  double median;

  // Exchange array1 <-> array2, if necessary
  if(array2Size < array1Size){
    EXCHANGE(array1, array2, aux);
    EXCHANGE(array1Size, array2Size, r);
  }

  // array1Size <= array2Size
  l = 0;
  r = array1Size;
  mediaSize = (array1Size + array2Size + 1) >> 1;
  while(1){
    i =  (l + r +1) >> 1;
    j = mediaSize -i;

    if((i) && (array1[i-1] > array2[j])){
      r = i - 1;
    }else if((i<array1Size) && (array2[j-1] > array1[i])){
      l = i + 1;
    }else{
      //if(((i==0) || (A[i-1] <= B[j])) && ((i==m) || (B[j-1] <= A[i]))){

      // Compute the median
      l = i>0?(j>0?(array1[i-1]>array2[j-1]?array1[i-1]:array2[j-1]):array1[i-1]):array2[j-1];

      if((array1Size + array2Size)&0x1){
	median = l;
      }else{
	r = i<array1Size?(j<array2Size?(array1[i]<array2[j]?array1[i]:array2[j]):array1[i]):array2[j];
	median = ((double)l+(double)r)/2;
      }
      break;

    }
  }
  return median;
}
