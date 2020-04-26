"""
Clare Minnerath
Assignment 3: #42 implementation
02/03/2020
"""

import matplotlib.pyplot as plt
import numpy as np
import time

count = 1

# Tiling problem #42
def tile(T, n, top_left, pos):
    global count
    
    # figure out what quadrant forbidden square is in & tile accordingly
    
    # forbidden square is in top left
    if pos[0]-top_left[0] < n//2 and pos[1]-top_left[1] < n//2:
        # tile accordingly
        T[top_left[0]+n//2-1,top_left[1]+n//2] = count 
        T[top_left[0]+n//2,top_left[1]+n//2] = count 
        T[top_left[0]+n//2,top_left[1]+n//2-1] = count 
        count+=1
        if n == 2:
            return
        else:
            # split up grid into 2^2 new quadrants
            tile(T,n//2,top_left,pos)   
            tile(T,n//2,(top_left[0],top_left[1]+n//2),(top_left[0]+n//2-1,top_left[1]+n//2))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]),(top_left[0]+n//2,top_left[1]+n//2-1))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]+n//2),(top_left[0]+n//2,top_left[1]+n//2))
    # forbidden square is in top right
    elif pos[0]-top_left[0] < n//2:
        T[top_left[0]+n//2-1,top_left[1]+n//2-1] = count #tl
        T[top_left[0]+n//2,top_left[1]+n//2] = count
        T[top_left[0]+n//2,top_left[1]+n//2-1] = count
        count+=1
        if n == 2:
            return
        else:
            tile(T,n//2,top_left,(top_left[0]+n//2-1,top_left[1]+n//2-1))   
            tile(T,n//2,(top_left[0],top_left[1]+n//2),pos)
            tile(T,n//2,(top_left[0]+n//2,top_left[1]),(top_left[0]+n//2,top_left[1]+n//2-1))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]+n//2),(top_left[0]+n//2,top_left[1]+n//2))
    # forbidden square is in bottom left
    elif pos[1]-top_left[1] < n//2:
        T[top_left[0]+n//2,top_left[1]+n//2] = count
        T[top_left[0]+n//2-1,top_left[1]+n//2-1] = count
        T[top_left[0]+n//2-1,top_left[1]+n//2] = count
        count+=1
        if n == 2:
            return
        else:
            tile(T,n//2,top_left,(top_left[0]+n//2-1,top_left[1]+n//2-1))   
            tile(T,n//2,(top_left[0],top_left[1]+n//2),(top_left[0]+n//2-1,top_left[1]+n//2))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]),pos)
            tile(T,n//2,(top_left[0]+n//2,top_left[1]+n//2),(top_left[0]+n//2,top_left[1]+n//2))
    # forbidden square is in bottom right
    else:
        T[top_left[0]+n//2-1,top_left[1]+n//2] = count%len(T)
        T[top_left[0]+n//2-1,top_left[1]+n//2-1] = count%len(T)
        T[top_left[0]+n//2,top_left[1]+n//2-1] = count%len(T)
        count+=1
        if n == 2:
            return
        else:
            tile(T,n//2,top_left,(top_left[0]+n//2-1,top_left[1]+n//2-1))   
            tile(T,n//2,(top_left[0],top_left[1]+n//2),(top_left[0]+n//2-1,top_left[1]+n//2))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]),(top_left[0]+n//2,top_left[1]+n//2-1))
            tile(T,n//2,(top_left[0]+n//2,top_left[1]+n//2),pos)
    
   
# binomial recursively        
def bin(n,k):
    if k==0 or n==k:
        return 1
    else:
        return bin(n-1,k-1)+bin(n-1,k)
    
# binomial w/ dynamic programming
def bin2(n,k):
    B = np.zeros((n+1,k+1))
    for i in range(n+1):
        for j in range(min(i,k)+1):
            if j==0 or j==i:
                B[i,j] = 1
            else:
                B[i,j] = B[i-1][j-1]+B[i-1][j]
    return B[n,k]

# binomial w/dynamic 1D array
def bin3(n,k):
    B = np.zeros(k+1)
    temp = 1
    for i in range(n+1):
        # Work backwards to not overwrite B[j] before needed
        for j in range(min(i,k),-1,-1):
            if j==0 or j==i:
                B[j] = 1
            else:
                B[j] = B[j]+B[j-1]
    return B[k]


Grid = np.zeros((16,16), np.int8)
Grid[2,7] = -6
tile(Grid,len(Grid),(0,0),(2,7))
print(Grid)
print()

print("Visual Grid: ")
im = plt.pcolormesh(Grid, cmap='prism', vmin=-1)
im.cmap.set_under('k')
plt.colorbar(extend='min')
plt.axis('off')
plt.show()
print()


print("Binomial Coefficient (Dynamic): ")
tic = time.perf_counter()    
print(bin2(11,4))
toc = time.perf_counter()
print(f"B. Coefficient calculated in {toc - tic:0.6f} seconds")
print()
print("Binomial Coefficient (Recursive): ")
tic = time.perf_counter()    
print(bin(11,4))
toc = time.perf_counter()
print(f"B. Coefficient calculated in {toc - tic:0.6f} seconds")
print()

print("Binomial Coefficient (Dynamic Single Array): ")
print(bin3(11,4))

        

        
        
        