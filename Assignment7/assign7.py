"""
Clare Minnerath
Assignment 7
03/28/2020
"""
# sum_of_subsets back tracking

include = [[2, False], [10, False], [13, False], [17, False], 
           [22, False], [42, False]]

total = 0
for pair in include:
    total += pair[0]

W = 52

def sum_of_subsets(i, weight, total):
    if promising(i, weight, total):
        if weight == W:
            solution = [pair[0] for pair in include if pair[1]==True]
            print("Solution:", solution)
        else:
            include[i+1][1] = True
            sum_of_subsets(i+1, weight+include[i+1][0], total - include[i+1][0])
            include[i+1][1] = False
            sum_of_subsets(i+1, weight, total - include[i+1][0])
            

def promising(i, weight, total):
    return (weight + total >= W) and (weight == W or weight + include[i+1][0] <= W)

sum_of_subsets(-1,0,total)
print()



# graph coloring backtracking

W = [[0,1,0,1,0,0],
     [1,0,1,0,1,0],
     [0,1,0,0,0,1],
     [1,0,0,0,1,0],
     [0,1,0,1,0,1],
     [0,0,1,0,1,0]]

vcolor = [0,0,0,0,0,0]
m = 3

def m_coloring(i):
    if is_promising(i):
        if i == len(W)-1:
            print(vcolor)
        else:
            for color in range(1,m+1):
                vcolor[i+1] = color
                m_coloring(i+1)
                
def is_promising(i):
    j = 0
    switch = True
    while(j<i and switch):
        if W[j][i] == 1 and vcolor[i]==vcolor[j]:
            switch = False
        j+=1
    return switch
            
            
m_coloring(-1)
            
            
            
            