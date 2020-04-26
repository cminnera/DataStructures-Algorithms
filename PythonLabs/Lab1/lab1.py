"""
Clare Minnerath
Lab 1
01/14/2020
"""

# algorithm 1.3 Exchange Sort

def exchange_sort(n,s):
    for i in range(n):
        for j in range(i+1,n):
            if(s[j]<s[i]):
                temp = s[i]
                s[i] = s[j]
                s[j] = temp

# algorithm 1.4 Matrix Multiplication
                
def matrix_mult(n, m1, m2, m3):
    for r in range(n):
        for c in range(n):
            for i in range(n):
                m3[r][c] = m3[r][c] + m1[r][i]*m2[i][c]
    return m3

# algorithm 1.6 nth Fibonacci Term (Recursive)
    
def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)

# algorithm 1.7 nth Fibonacci Term (Iterative)

def fib2(n):
    fibs = []
    fibs.append(0)
    if n>0:
        fibs.append(1)
        for i in range(2,n+1):
            fibs.append(fibs[i-1] + fibs[i-2])
            
    return fibs[n]



# main
                
S = [10,7,11,5,13,8]

print("Unordered List:", S)
exchange_sort(len(S),S)
print("Ordered List:", S)
print()

matrix1 = [[2,3],[4,1]]
matrix2 = [[5,7],[6,8]]
matrix3 = [[0,0],[0,0]]

print("Matrix product:",matrix_mult(len(matrix1),matrix1,matrix2, matrix3))
print()

n = 7
print("The ", n, "th fibonacci term:", fib(n))
print()

print("The ", n, "th fibonacci term:", fib2(n))
print()





