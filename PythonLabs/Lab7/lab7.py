"""
Clare Minnerath
Lab 7
03/05/2020
"""


def shortest_job_first(JS):
    jobs = []
    time = 0
    # order so that the shortest_job is selected first
    JS.sort(key=lambda x: x[1])
    # done when all jobs scheduled
    while JS:
        # selection
        time += JS[0][1]*len(JS)
        jobs.append(JS.pop(0)[0])
        
    return jobs, time
    

# choose the highest_reward for each deadline
def highest_reward_scheduling(JS):
    reward = 0
    curr_deadline = 0
    jobs = []
    # order so by deadline, then at each deadline by highest reward
    JS.sort(key = lambda x: (x[1],-x[2]))
    # done when all jobs are scheduled or discarded
    while JS:
        curr_deadline += 1
        # feasibility check
        if JS[0][1] == curr_deadline:
            reward += JS[0][2]
            jobs.append(JS.pop(0)[0])
            # discard already passed deadlines
            while JS and JS[0][1] == curr_deadline:
                JS.pop(0)
    return jobs, reward
    

js = [(1,7),(2,3),(3,10),(4,5)]
print(shortest_job_first(js))

js2 = [(1, 2, 40),(2, 4, 15),(3, 3, 60),(4, 2, 20),
       (5, 3, 10),(6, 1, 45),(7, 1, 55)]
print(highest_reward_scheduling(js2))