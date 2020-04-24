"""
Clare Minnerath
Assignment 9
04/23/2020
"""

# Is Heap

def is_heap(L):
    for i in range(0, len(L)//2):
        if L[2*i+1]>L[i] or 2*i + 2 < len(L) and L[2*i+2]>L[i]:
            return False
    return True
            

# Class that allows for following functions to create
# heap and implement heapsort
class heap:
    def __init__(self, bTree, Size_list):
        self.S = bTree
        self.size = Size_list



def sift_down(H, i):
    siftkey = H.S[i-1]
    parent = i
    spotfound = False

    while not spotfound and 2*parent <= H.size:
        if 2*parent < H.size and H.S[2*parent-1] < H.S[2*parent]:
            largerchild = 2*parent+1
        else:
            largerchild = 2*parent
        if siftkey<H.S[largerchild-1]:
            H.S[parent-1] = H.S[largerchild-1]
            parent = largerchild
        else:
            spotfound = True
    H.S[parent-1] = siftkey

    
def root(H):
    keyout = H.S[0]
    H.S[0] = H.S[H.size-1]
    H.size -= 1
    sift_down(H, 1)
    return keyout

def remove_keys(H):
    for i in range(H.size,1, -1):
        H.S[i-1] = root(H)
    

def make_heap(h):
    for i in range(h.size//2, 0, -1):
        sift_down(h, i)

def heap_sort(h):
    make_heap(h)
    remove_keys(h)


h1 = heap([2,4,5,3,1,9,6,7,10,8], 10)
print(h1.S)
heap_sort(h1)
print(h1.S)
print()


h2 = heap([3,8,5,1,9,12,2,6,11,7], 10)
if is_heap(h2.S):
    print("Heap:")
    print(h2.S)
else:
    print("Not a heap:")
    print(h2.S)
make_heap(h2)
if is_heap(h2.S):
    print("Heap:")
    print(h2.S)
else:
    print("Not a heap:")
    print(h2.S)
print()


# Hashing using linear probing

class hash:
    def __init__(self, func, table_size):
        self.h_func = func
        self.table = []
        for i in range(table_size):
            # make this a value that won't be hashed
            # for a mod has function -1 is fine
            self.table.append(-1)
    def add_hash_element(self, ele):
        k = self.h_func(ele)
        while self.table[k] != -1:
            k += 1
        self.table[k] = ele
    def delete_hash_element(self, ele):
        k = self.h_func(ele)
        while self.table[k] != ele:
            k += 1
        self.table[k] = -1
def hash_func1(e):
    return e % 10
        
basic_hash = hash(hash_func1, 100)


