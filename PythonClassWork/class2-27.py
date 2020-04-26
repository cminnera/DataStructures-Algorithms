"""
Clare Minnerath
Class 2/27
Greedy Change Alg.
"""

amount_owed = 16
coins = [1,5,10,12,25]
current_amount = 0
solved = False
change = {}

while not solved:
    choice_valid = False
    coins_left = coins
    while not choice_valid:
        # selection
        choice = max(coins_left)
        
        # feasibility check
        if current_amount + choice <= amount_owed:
            choice_valid = True
        else:
            coins_left.remove(choice)
            
    current_amount += choice
    if choice not in change:
        change[choice] = 1
    else:
        change[choice] += 1
    
    # solution check
    if current_amount == amount_owed:
        solved = True
        
print(change)

