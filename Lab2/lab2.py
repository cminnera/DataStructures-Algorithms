"""
Clare Minnerath
Lab 2
01/22/2020
"""


# 1.5 Binary Search iterative
def binary_search(x,L):
    low = 0
    high = len(L)
    
    while low<=high:
        mid = int((low+high)/2)
        if x == L[mid]:
            return mid
        elif x<L[mid]:
            high = mid-1
        else:
            low = mid+1
    return -1
            

# 2.1 Binary Search recursive
def binary_search2(low,high,L,x):
    if low>high:
        return -1
    else:
        mid = int((low+high)/2)
        if x == L[mid]:
            return mid
        elif x<L[mid]:
            return binary_search2(low,mid-1,L,x)
        else:
            return binary_search2(mid+1,high,L,x)
        

# 2.2 Merge Sort
def mergesort(L):
    if len(L)>1:
        L1 = L[:len(L)//2]
        L2 = L[len(L)//2:]
        mergesort(L1)
        mergesort(L2)
        L = merge(L1,L2,L)
    
def merge(l1,l2,merged):
    i=0
    j=0
    k=0
    while i<len(l1) and j<len(l2):
        if l1[i]<l2[j]:
            merged[k]=l1[i]
            i+=1
        else:
            merged[k]=l2[j]
            j+=1
        k+=1
    if i>=len(l1):
        while j<len(l2):
            merged[k]=l2[j]
            j+=1
            k+=1
    else:
        while i<len(l1):
            merged[k]=l1[i]
            i+=1
            k+=1
    return merged
        
            

# main
            
l = [2,3,6,8,12,13,18] 
X = 12

print("Found ",X ,"at", binary_search(X,l))
print()

print("Found ",X ,"at", binary_search2(0,len(l),l,X))
print()

l2 = [2,7,1,8,3,4,5,12,6,14,10]

mergesort(l2)

print("Merge Sorted Array:")
print(l2)
            
            
            
            