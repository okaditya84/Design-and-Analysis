
def shortest_path(graph, start):# time complexity of dijkstra's algorithm is O(ElogV)
    distances = {node: float("inf") for node in graph} # this takes O(n) n is the number of all nodes in graphs
    distances[start] = 0 #this takes O(1)
    visited = list()# this takes O(1)
    unvisited = list(graph.keys())
    current = start
    while unvisited:#time complexity of this loop is O(V)       
        for neighbor in graph[current]:
            if neighbor not in visited:
                print(distances[neighbor], distances[current] + graph[current][neighbor])
                distances[neighbor] = min(distances[neighbor], distances[current] + graph[current][neighbor])
        visited.append(current)
        unvisited.remove(current)
        if(unvisited):
            current = min(unvisited, key=lambda node: distances[node])
    return distances

#take user input
n = int(input("Enter the number of nodes: "))
graph = dict()
for i in range(n):
    print("Enter the node and its neighbors: node neighbor1 weight1 neighbor2 weight2", end = ": ")
    node, neighbor1, weight1, neighbor2, weight2 = input().split()
    graph[node] = {neighbor1: int(weight1), neighbor2: int(weight2)}
start = input("Enter the starting node: ")
distances = shortest_path(graph, start)
print("The shortest distances from the starting node are: ", distances)

