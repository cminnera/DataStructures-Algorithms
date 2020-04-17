"""
Clare Minnerath
03/02/2020
Assignment 5
"""


def greedy_min_bins(L):
    # helpful for selection
    L.sort(reverse=True)
    print(L)
    bins = []
    b = 0
    
    # reached solution when all objects are in a bin (L = [])
    while L:
        bins.append(0.0)
        i = 0
        # select largest (first in list)
        while i < len(L):
            # check if feasable (does it fit?)
            if L[i]+bins[b] <= 1:
                bins[b] += L[i]
                del L[i]
            else:
                i+=1
        b += 1
        
    return len(bins)


# example that works optimally
l = [0.66, 0.8, 0.25, 0.03, 0.5, 0.44, 0.7, 0.12, 0.07, 0.38, 0.22]
print("Bins:", greedy_min_bins(l))

print()

# example where algorithm does not work optimally (possible to have in 2 bins)
l = [.6, .33, .34, .33, .22, .08, .08]
print("Bins:", greedy_min_bins(l))

