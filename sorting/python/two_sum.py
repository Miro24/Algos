"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

"""

class Solution(object):
    def bubblesort(self, list):
        """
        : type list: List[[int, pos]] 
        """
        n = len(list)
        newn = n;
        while newn>1:
            n = 0
            for i in range(1,newn):
                if list[i-1][0]>list[i][0]:
                    list[i-1],list[i],n = list[i], list[i-1], i
            newn = n

    def maxHeapify(self, list, size, i):
        while True:
            l = 2*i
            r = 2*i + 1
            largest = i
            if (l<=size) and (list[l-1][0] > list[i-1][0]):
                largest = l

            if (r<= size) and (list[r-1][0] > list[largest-1][0]):
                largest = r

            if largest != i:
                list[i-1], list[largest-1] = list[largest-1], list[i-1]
                i = largest
            else:
                break

    def buildMaxHeap(self, list):
        for i in range(len(list)//2,0,-1):
            self.maxHeapify(list, len(list), i)

    def heapSort(self, list):
        self.buildMaxHeap(list)
        for i in range(len(list),1,-1):
            list[0], list[i-1] = list[i-1], list[0]
            self.maxHeapify(list, i-1, 1)


    def mergeSort(self, list):
        """
        :type list: Lis[[int,int]]
        """
        listOfList = []
        for l in list:
            listOfList.append([l])

        i = len(listOfList)
        while i > 1:
            for j in range(i//2):
                # merge
                tmp = listOfList.pop(j)
                p = 0 
                while True:            
                    if len(tmp) == 0:
                        break;
                    elif p == (len(listOfList[j])):
                        listOfList[j].extend(tmp)
                        break;
                    else:
                        if(tmp[0][0]<listOfList[j][p][0]):
                            listOfList[j].insert(p, tmp.pop(0))
                            p = p+1
                        else:
                            p = p +1
            i = len(listOfList)

        for i in range(len(list)):
            list[i] = listOfList[0][i]

        
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        list = []
        for i in range(len(nums)):
            list.append([nums[i],i])

        # Sort the list
        #self.bubblesort(list)
        #self.heapSort(list)
        self.mergeSort(list)
        
        i,j=0,(len(list)-1)
        while True:
            s = list[i][0] + list[j][0]
            if s == target:
                break
            elif s< target:
                i = i+1
            else:
                j = j-1

        if list[i][1]< list[j][1]:
            return [list[i][1],list[j][1]]
        else:
            return [list[j][1],list[i][1]]


list = [[0,4,3,0], 0]
print(list)
x = Solution()
print(x.twoSum(list[0], list[1]))
