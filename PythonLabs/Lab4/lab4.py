"""
Clare Minnerath
Lab 4
02/04/2020
"""

import numpy as np
import random
import sys
import math


def path_A_to_G(m):
    dis = 0
    cur = 0
    path = [0]
    while m[cur,6] == 0 or m[cur,6]==math.inf:
        dest = cur + 1
        while m[cur,dest] == 0 or m[cur,dest]==math.inf:
            dest = dest + 1
        dis += m[cur,dest]
        path.append(int(dest))
        cur = dest
    path.append(int(6))
    dis +=m [cur,6]
    return path, int(dis)


def path_A_to_node(m,n):
    dis = 0
    cur = 0
    path = [0]
    while m[cur,n] == 0 or m[cur,n]==math.inf:
        dest = cur+1
        while m[cur,dest] == 0 or m[cur,dest]==math.inf:
            dest = dest + 1
        dis += m[cur,dest]
        path.append(int(dest))
        cur = dest
    path.append(int(n))
    dis +=m [cur,n]
    return path, int(dis)

# Floyd's algorithm
def shortest_path_A_to_G(m):
    d = m
    for k in range(len(m)):
        for i in range(len(m)):
            for j in range(len(m)):
                d[i,j] = min(d[i,j], d[i,k]+d[k,j])
                
    return int(d[0,6])
        

AM = np.matrix( [[0, 2, 4, 7, math.inf, 5, math.inf],
                 [2, 0, math.inf, 6, 3, math.inf, 8],
                 [4, math.inf, math.inf, 0, math.inf, 6, math.inf],
                 [7, 6, math.inf, 0, math.inf, 1, 6], 
                 [math.inf, 3, math.inf, math.inf, 0, math.inf, 7],
                 [5, math.inf, 6, 1, math.inf, 0, 6], 
                 [math.inf, 8, math.inf, 6, 7, 6, 0]])
   
print("Weight Matrix: ")
print(AM)
print()

p,d = path_A_to_G(AM)
print("Path form A to G: ")
print(p)
print("Distance Traveled: ")
print(d)
print()


DfA = [0]
print("Distance from A to other nodes: ")
for i in range(1,len(AM)):
    DfA.append(path_A_to_node(AM,i)[1])

print(DfA)
print()


print("Shorted path from A to G: ")
print(shortest_path_A_to_G(AM))
