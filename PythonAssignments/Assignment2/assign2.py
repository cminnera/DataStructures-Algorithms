"""
Clare Minnerath
Assignment 2
01/30/2020
"""

# Binary Search w/ guaranteed find

def binary_search(low,high,L,x):
    mid = int((low+high)/2)
    if x == L[mid]:
        return mid
    elif x<L[mid]:
        return binary_search(low,mid-1,L,x)
    else:
        return binary_search(mid+1,high,L,x)



S = [4,6,12,15,21,22,29,34,41,44]
print(binary_search(0,len(S)-1,S,22))
