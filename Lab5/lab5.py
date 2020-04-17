"""
Clare Minnerath
Lab 5
02/11/2020
"""

import random


def matrix_to_adj_list(m):
    adj = []
    row = []
    for x in range(len(m)):
        for y in range(len(m)):
            if m[x][y]==1:
                row.append(y)
        adj.append(row[:])
        row.clear()
    return adj
    
# random path
def adj_to_path(a,n1,n2):
    j=n1
    path = [n1]
    while(n2 not in a[j]):
        temp = random.randint(0,len(a[j])-1)
        path.append(a[j][temp])
        j = a[j][temp]
    path.append(n2)
    return path
        

      

M = [[0, 1, 0, 0, 1],
     [1, 0, 1, 1, 1],
     [0, 1, 0, 1, 0],
     [0, 1, 1, 0, 1],
     [1, 1, 0, 1, 0]]

ADJ = matrix_to_adj_list(M)
print(ADJ)

print(adj_to_path(ADJ,0,2))


# C.
# We could use a breadth first search to determine the shortest path between 
# two points. Because we are using an adjacency list, there is no weight 
# that needs to be incorporated into the algorithm. For the breadth first
# search we would look first at the nodes directly adjacent to the start
# node. Then, we would set up a queue to search the nodes 2 away from the
# start node steamming from the nodes 1 away. As soon as we reach the 
# end node, we can stop the search and have found a shortest path. (There
# could technically be more than one, which we could check all the nodes
# at that level to find all shortest paths)




