
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



list = [[2,7,1,9], [0,4,3,0]]
print("List to sort: ", list)
for l in list:
    bubblesort(l)
    print("Sorted list", l)
    print("\n")


