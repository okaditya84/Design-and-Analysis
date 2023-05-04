def shortest_path(graph, start):
    distances = {node: float("inf") for node in graph}
    distances[start] = 0
    visited = list()
    unvisited = list(graph.keys())
    current = start
    while unvisited:
        for neighbor in graph[current]:
            if neighbor not in visited:
                print( distances[neighbor], distances[current] + graph[current][neighbor])
                distances[neighbor] = min(distances[neighbor], distances[current] + graph[current][neighbor])
        visited.append(current)
        unvisited.remove(current)
        if(unvisited):
            current = min(unvisited, key=lambda node: distances[node])
    return distances

graph = { "a": {"b": 2, "c": 1}, "b": {"a": 2, "c": 3}, "c": {"a": 1, "b": 3} } 
print(shortest_path(graph, "a"))



