"""
Clare Minnerath
1st Online Assignment - Assign 6
03/24/2020
"""

col = []
n = 8
for i in range(n):
    col.append(0)
count = 0

def queens(i):
    if promising(i):
        if i == n-1:
            print(col)
            global count
            count+=1
        else:
            for j in range(0,n):
                col[i+1] = j
                queens(i+1)        

def promising(i):
    switch = True
    k=0
    
    while k<i and switch:
        if col[i] == col[k] or abs(col[i]-col[k]) == i-k:
            switch = False
        k+=1
    return switch

queens(-1)
print("# Solutions: ",count)



