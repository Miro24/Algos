"""
BUBBLE SORT
"""
def bubblesort(list):
    """
    : type list: List[int]
    """
    n = len(list)
    newn = n;
    while newn>1:
        n = 0
        for i in range(1,newn):
            if list[i-1]>list[i]:
                list[i-1],list[i],n = list[i], list[i-1], i
        newn = n
    pass


"""
HEAP SORT
"""
def maxHeapify(list, size, i):
    while True:
        l = 2*i
        r = 2*i + 1
        largest = i
        if (l<=size) and (list[l-1] > list[i-1]):
            largest = l

        if (r<= size) and (list[r-1] > list[largest-1]):
            largest = r
        if largest != i:
            list[i-1], list[largest-1] = list[largest-1], list[i-1]
            i = largest
        else:
            break

def buildMaxHeap(list):
    for i in range(len(list)//2,0,-1):
        maxHeapify(list, len(list), i)

def heapSort(list):
    buildMaxHeap(list)
    for i in range(len(list),1,-1):
        list[0], list[i-1] = list[i-1], list[0]
        maxHeapify(list, i-1, 1)

"""
MERGER SORT
"""


def mergeSort(list):
    """
    : type list: List[int]
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
                    if(tmp[0]<listOfList[j][p]):
                        listOfList[j].insert(p, tmp.pop(0))
                        p = p+1
                    else:
                        p = p +1
        i = len(listOfList)

    for i in range(len(list)):
        list[i] = listOfList[0][i]
        


list = [[2,7,1,9], [0,4,3,0]]
print("List to sort: ", list)
for l in list:
    #bubblesort(l)
    #heapSort(l)
    mergeSort(l)
    print("Sorted list", l)
    print("\n")


