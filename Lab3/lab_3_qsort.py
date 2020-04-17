
import random

# quicksort with partition algorithm for lab 3
# algorithms 2.6 and 2.7
count=0

def partition(S, low, high):
    # print("Before partition: ",S[low:high+1])
    pivot_item = S[low]
    global count
    count+=1
    j = low
    for i in range(low + 1, high + 1):
        if S[i] < pivot_item:
            j += 1
            S[i], S[j] = S[j], S[i]
    pivot = j
    S[low], S[pivot] = S[pivot], S[low]
    # print("After partition: ",S[low:high+1])
    # print("Pivot: ",pivot_item)
    return pivot


def rand_partition(S, low, high):
    p = random.randint(low, high)
    global count
    count+=1
    pivot_item = S[p]
    S[low], S[p] = S[p], S[low]
    
    j = low
    for i in range(low + 1, high + 1):
        if S[i] < pivot_item:
            j += 1
            S[i], S[j] = S[j], S[i]
    pivot = j
    S[low], S[pivot] = S[pivot], S[low]
    return pivot

   
def quicksort(S, low, high):
    if high > low:
        # random pivot
        pivot = rand_partition(S, low, high)
        
        # first item pivot
        # pivot = partition(S, low, high)
        
        quicksort(S, low, pivot - 1)
        quicksort(S, pivot + 1, high)


S = []

# for x in range(100):
#     S.append(random.randint(0, 1000))
    
S = [32,25,22,15,13,12,10,8,4,3,2,1]

quicksort(S, 0, len(S) - 1)
print("# of partitions:" ,count)
print(S)
