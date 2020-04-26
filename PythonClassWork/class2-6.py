"""
Clare Minnerath
Dynamic Programming 
02/06/2020
"""

def robot_coin_collection(C):
    row = len(C)
    col = len(C[0])
    F = [[C[0][0]]]
    for j in range(1,col):
        # first row
        F[0].append(F[0][j-1]+C[0][j])
    
    for i in range(1,row):
        # first col
        F.append([F[i-1][0]+C[i][0]])
        # rest of rows in order
        for j in range(1, col):
            F[i].append(max(F[i-1][j],F[i][j-1])+C[i][j])
    for item in F:
        print(item)
    return F[row-1][col-1]

C = [[0,0,0,0,1,0,],
     [1,1,0,1,0,0],
     [0,0,0,1,0,1],
     [0,0,1,0,0,1],
     [1,0,0,0,1,0]]

print(robot_coin_collection(C))
    
    
    
    