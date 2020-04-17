"""
Clare Minnerath
02/10/2020
Assignment 4
"""

import itertools 
import sys

# -1 will mark impassable square
# coins can't be -1 valued
x = -1

def robot_coin_collection(C):
    global x
    row = len(C)
    col = len(C[0])
    F = [[C[0][0]]]
    for j in range(1,col):
        # first row
        if F[0][j-1]==x:
            for k in range(j,col):
                F[0].append(x)
            break
        F[0].append(F[0][j-1]+C[0][j])
    
    nopath = False 
    for i in range(1,row):
        # first col
        if F[i-1]==x or nopath:
            nopath = True
            F.append(x)
        else:
            F.append([F[i-1][0]+C[i][0]])
        # rest of rows in order
        for j in range(1, col):
            if (F[i-1][j] == x and F[i][j-1] == x) or C[i][j]==x:
                F[i].append(x)
            elif F[i-1][j] == x:
                F[i].append(F[i][j-1] + C[i][j])
            elif F[i][j-1] == x:
                F[i].append(F[i-1][j]+C[i][j])
            else:
                F[i].append(max(F[i-1][j],F[i][j-1])+C[i][j])
    for item in F:
        print(item)
    return F[row-1][col-1]

def find_subsets(s): 
    subsets = []
    for i in range(len(s)+1):
        for j in itertools.combinations(s,i):
            subsets.append(set(j))
    return subsets


# Messy and doesn't quite work, but this is what we got
def travel(W):
    D = [[]]
    V = []
    for i in range(len(W)):
        V.append(i)
    V_no_v0 = find_subsets(V[1:])
    for i in range(len(V_no_v0)):
        D[0].append(0)
    for i in range(1,len(W[0])):
        D.append([0])
        for j in range(1,len(V_no_v0)):
            D[i].append(0)
    P = D.copy()
    for i in range(1, len(W)):
        D[i][0] = W[i][0]
    for item in D:
        print(item)
    for k in range(1,len(W)):
        for s in V_no_v0[1:]:
            if len(s) == k:
                for i in range(1,len(W)):
                    if i not in s:
                        index = V_no_v0.index(s)
                        m = sys.maxsize
                        for j in s:
                            sc = s.copy()
                            sc.remove(j)
                            if sc is not None:
                                if W[i][j] + D[j][V_no_v0.index(sc)] < m:
                                    D[i][index] = W[i][j] + D[j][V_no_v0.index(sc)]
                                    m = D[i][index]
                                    P[i][index] = j
    m = sys.maxsize
    for j in range(1,len(W)):
        if W[i][j] + D[j][V_no_v0.index(set(V[1:j-1]+V[j+1:]))] < m:
            D[0][len(V_no_v0)-1] = W[1][j] + D[j][V_no_v0.index(set(V[1:j-1]+V[j+1:]))]
            m = D[0][len(V_no_v0)-1]
            P[0][len(V_no_v0)-1] = j
    minlength = D[0][len(V_no_v0)-1]
    for item in D:
        print(item)
    return minlength
        
    



C = [[0,x,0,1,0,0],
     [1,0,1,x,1,1],
     [0,1,0,x,1,0],
     [0,0,0,1,0,1],
     [x,x,x,0,1,0]]

print(robot_coin_collection(C))


C = [[0,0,4,0,1,0,],
     [1,1,0,1,0,3],
     [0,0,0,1,0,1],
     [2,0,1,0,0,6],
     [1,0,0,0,1,0],
     [0,1,0,0,1,0]]

print(travel(C))


