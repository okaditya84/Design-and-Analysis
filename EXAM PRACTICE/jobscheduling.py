def jobScheduling(jobs):
    jobs = sorted(jobs, key = lambda x: x[0], reverse = True)
    print(jobs)
    maxDeadline = max(jobs, key = lambda x: x[1])[1] # Find the maximum deadline
    jobList = [0] * maxDeadline # Create a list of size maxDeadline and initialize it with 0
    profit = 0
    print( jobs[0][1])
    print(jobs[1][0])
    for i in range(len(jobs)):
        for j in range(jobs[i][1]-1, -1, -1):
            print(jobs[i][1])
            if jobList[j] == 0:
                jobList[j] = 1
                profit+=jobs[i][0]
                break
    return sum(jobList), profit


n = int(input("Enter the number of jobs: "))
jobs = []
for i in range(n):
    print("Enter the profit and deadline of the job: profit deadline", end = ": ")
    profit, deadline = map(int, input().split())
    jobs.append((profit, deadline))

jobsDone, profit = jobScheduling(jobs)
print("The maximum profit that can be earned is: ", profit)
print("The jobs that can be done are: ", jobsDone)


