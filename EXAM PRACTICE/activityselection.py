activities = []
n = int(input("Enter the number of Activities: "))
for i in range(n):
    print("Enter the start and finish time of the activities: start finish", end = ": ")
    start, finish = map(int, input().split())
    while(start >= finish):
        print("Start time cannot be greater than or equal to finish time, enter again:")
        start, finish = map(int, input().split())
    activities.append((start, finish))
    print(activities)

def greedyActivity(activities):
    activities.sort(key = lambda x: x[1])
    jobs = 0
    jobList = []
    for i in range(len(activities)):
        if(i == 0):
            jobs+=1
            jobList.append(activities[i])
        else:
            if(activities[i][0] >= jobList[-1][1]):
                jobs+=1
                jobList.append(activities[i])
    return jobs, jobList

jobs, jobList = greedyActivity(activities)
print("The maximum number of jobs that can be done are: ", jobs)
print("The jobs that can be done are: ", jobList)