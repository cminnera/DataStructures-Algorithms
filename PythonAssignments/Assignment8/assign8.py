"""Clare MinnerathAssignment 804/12/2020Knapsack problem w/ backtracking & optimizationKnapsack problem w/ branch & bound (BFS)"""# using a class to store variables/functions for backtracking alg.class ks:        def __init__(self, W, container, all_profits, all_weights):        self.numbest = 0        self.maxprofit = 0        self.k = 0        self.W = W        self.bestset = []        self.contain = container        self.p = all_profits        self.w = all_weights            def knapsack(self, i, profit, weight, move_L):        if weight <= self.W and profit > self.maxprofit:            self.maxprofit = profit            self.numbest = i            self.bestset = self.contain.copy()              if move_L and i < self.k:            if i == self.k-1:                self.contain[i+1] = False                self.knapsack(i+1, profit, weight, False)            else:                self.contain[i+1] = True                self.knapsack(i+1, profit + self.p[i+1], weight + self.w[i+1], True)                self.contain[i+1] = False                self.knapsack(i+1, profit, weight, False)        elif self.promising(i, profit, weight):            self.contain[i+1] = True            self.knapsack(i+1, profit + self.p[i+1], weight + self.w[i+1], True)            self.contain[i+1] = False            self.knapsack(i+1, profit, weight, False)        def promising(self, i, prof, weigh):        if weigh>=self.W:            return False        else:            j = i + 1            bound = prof            totalweight = weigh            while j < len(self.w)-1 and totalweight + self.w[j] <= self.W:                totalweight += self.w[j]                bound += self.p[j]                j += 1            self.k = j            if self.k < len(self.w)-1:                bound += (self.W - totalweight) * (self.p[self.k]/self.w[self.k])            return bound > self.maxprofit            def print_solution(self):        for i in range(self.numbest+1):            if self.bestset[i]:                print("Include ", i)        print("Profit: ", self.maxprofit)                    W33 = 9include33 = [False, False, False, False, False]all_profits33 = [20, 30, 35, 12, 3]all_weights33 = [2, 5, 7, 3, 1]knapsack33 = ks(W33, include33, all_profits33, all_weights33)knapsack33.knapsack(-1, 0, 0, False)print("#33 solution")knapsack33.print_solution()W56 = 14include56 = [False, False, False, False]all_profits56 = [40,30,50,10]all_weights56 = [2, 5, 10, 5]print()knapsack56 = ks(W56, include56, all_profits56, all_weights56)knapsack56.knapsack(-1, 0, 0, False)print("Ex 5.6 solution")knapsack56.print_solution()# Branch and Bound alg. w/ class for node objectclass node:    def __init__(self, level, profit, weight, items):        self.level = level        self.profit = profit        self.weight = weight        self.items = items    def __repr__(self):        return "level:%s weight:%s" %(self.level, self.weight)def knapsack2(p, w, W):    v = node(-1, 0, 0, [])    Q = []    bestitems = []    Q.append(v)    maxprofit = 0    while Q:        v = Q.pop(0)        u = node(v.level+1, v.profit + p[v.level+1],                 v.weight + w[v.level+1], v.items.copy())        u.items.append(v.level+1)        if u.weight <= W and u.profit > maxprofit:            maxprofit = u.profit            bestitems = u.items        if bound(u, W, p, w) > maxprofit:            Q.append(u)        u2 = node(v.level + 1, v.profit, v.weight, v.items.copy())        if bound(u2, W, p, w) > maxprofit:            Q.append(u2)    return bestitems, maxprofit    def bound(u, W, p, w):    if u.weight >= W:        return 0    else:        result = u.profit        j = u.level + 1        totalweight = u.weight        while j < len(w) and totalweight + w[j] <= W:            totalweight += w[j]            result += p[j]            j+=1        k = j        if k < len(w):            result += (W-totalweight)*(p[k]/w[k])    return result        profits = [20, 30, 35, 12, 3]weights = [2, 5, 7, 3, 1]W = 13solution_items, solution_profit = knapsack2(profits, weights, W)print()print("Include: ", solution_items)print("Profit: ", solution_profit)