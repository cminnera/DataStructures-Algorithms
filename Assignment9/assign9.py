"""
Clare Minnerath
Assignment 9
04/23/2020
"""


def is_heap(L):
    for i in range(0, len(L)//2):
        if L[2*i+1]>L[i] or 2*i + 2 < len(L) and L[2*i+2]>L[i]:
            return False
    return True
            

class heap:
    S = [2,4,5,3,1,9,6,7,10,8]
    size = 10



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
    print(h.S)
    print(is_heap(h.S))
    remove_keys(h)


h1 = heap
print(h1.S)
print(is_heap(h1.S))
heap_sort(h1)
print(h1.S)
