"""
Clare Minnerath
Lab 6
02/18/2020
"""



class Node:
    def __init__(self, item):
        self.item = item
        self.left = None
        self.right = None
              
class BST:
    def __init__(self):
        self.root = None
               
    def add_node(self, item):
        new_node = Node(item)
        r = self.root
        i = None
        
        while r:
            i = r
            if item > r.item:
                r = r.right
            else:
                r = r.left
        
        if not i:
            self.root = new_node
        elif item > i.item:
            i.right = new_node
        else:
            i.left = new_node
           
    def print_inorder(self, r):
        if r:
            self.print_inorder(r.left)
            print(r.item)
            self.print_inorder(r.right)

my_tree = BST()
my_tree.add_node(7)
my_tree.add_node(5)
my_tree.add_node(11)   
my_tree.add_node(6)

#       7
#     /  \
#    5   11
#     \
#     6

my_tree.print_inorder(my_tree.root)
            



