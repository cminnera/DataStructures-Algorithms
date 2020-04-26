"""
Clare Minnerath
02/13/2020
Graph Traversals
"""

def depth_first(G, start, end):
    found = False
    path = []
    adjacency_queue = []
    vertex_stack = [start]
    is_marked = [False]*len(G)    
    
    while vertex_stack and not found:
        v = vertex_stack.pop()
        if v == end:
            path.append(v)
            found = True
        else:
            if not is_marked[v]:
                is_marked[v] = True
                path.append(v)
                
                adjacency_queue.clear()
                # this for loop should use enumerate
                for edge in range(len(G[v])):
                    if G[v][edge]!=0:
                        adjacency_queue.append(edge)
                
                while adjacency_queue:
                    v = adjacency_queue.pop(0)
                    if not is_marked[v]:
                        vertex_stack.append(v)
    return path

def breadth_first(G, start, end):
    found = False
    path = []
    adjacency_queue = []
    vertex_queue = [start]
    is_marked = [False]*len(G)    
    
    while vertex_queue and not found:
        v = vertex_queue.pop(0)
        if v == end:
            path.append(v)
            found = True
        else:
            if not is_marked[v]:
                is_marked[v] = True
                path.append(v)
                
                adjacency_queue.clear()
                # this for loop should use enumerate
                for edge in range(len(G[v])):
                    if G[v][edge]!=0 and G[v][edge]!= x:
                        adjacency_queue.append(edge)
                
                while adjacency_queue:
                    v = adjacency_queue.pop(0)
                    if not is_marked[v]:
                        vertex_queue.append(v)
    return path      


G = [[0,1,1,1,0,0,0,0,0,0],
     [1,0,0,0,1,1,0,0,0,0],
     [1,0,0,0,0,0,0,1,0,0],
     [1,0,0,0,0,0,0,0,1,0],
     [0,1,0,0,0,0,1,0,0,0],
     [0,1,0,0,0,0,0,0,0,0],
     [0,0,0,0,1,0,0,0,0,0],
     [0,0,1,0,0,0,0,0,0,0],
     [0,0,0,1,0,0,0,0,0,1],
     [0,0,0,0,0,0,0,0,1,0]]

print(depth_first(G,4,9))
print(breadth_first(G,0,9))
print()

x = 'x'
G2 = [[0,200,x,x,x,x,160],
      [200,0,x,780,x,900,x],
      [x,1300,0,x,600,x,x],
      [x,x,x,0,1400,1000,x],
      [x,x,600,x,0,x,800],
      [x,x,x,1000,x,0,x],
      [x,x,x,x,800,x,0]]


print(depth_first(G2,0,6))
print(breadth_first(G2,0,9))

