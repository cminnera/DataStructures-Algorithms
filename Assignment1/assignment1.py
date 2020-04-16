
"""
Clare Minnerath
Assignment 1
01/19/2020
"""

# 2. smallest numbers
def smallest_nums(m,n):
    smallNums = []
    
    # insertion sort to order array
    for i in range(1, len(n)): 
        key = n[i] 
        j = i-1
        
        while j >= 0 and key < n[j] : 
                n[j + 1] = n[j] 
                j -= 1
        n[j + 1] = key
        
    # form list of m elements from sorted list
    for i in range(m):
        smallNums.append(n[i])
        
    return smallNums

        
# 3. sets of 3 from a list
def print_sets_of3(n):
    for i in range(len(n)):
        for j in range(i+1,len(n)):
            for k in range(j+1,len(n)):
                print("[",n[i],",",n[j],",",n[k],"]")
                
# 5. GCD - recursive
def GCD(x,y):
    if y==0:
        return x
    return GCD(y,x%y)


# 7. AC - binary tree is heap?
def binary_is_heap(n,i):
    if 2*i+1>=len(n):
        return True
    elif 2*i+2<len(n):
        if n[i]>=n[2*i+1] and n[i]>=n[2*i+2]:
            return binary_is_heap(n,2*i+1) and binary_is_heap(n,2*i+2)
        else:
            return False
    elif 2*i+1<len(n):
        return n[i]>=n[2*i+1]
        



# main
    
N = [2,6,12,9,5,11,8]
M = [3,4,5,2]
L = [12,9,8,9,8,4,3,5,5,3]
print(smallest_nums(6,N))
print()
print_sets_of3(M)
print()
print(GCD(7398,2877))
print()
print(binary_is_heap(L,0))

