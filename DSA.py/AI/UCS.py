class Graph:
    def __init__(self, graph):
        self.graph = graph

    def ucs(self, start, goal):
        visited = set()
        queue = [(0, start, [start])]

        while queue:
            cost, node, path = queue.pop(0)
            if node == goal:
                return path, cost
            if node not in visited:
                visited.add(node)
                for neighbor, weight in self.graph[node].items():
                    if neighbor not in visited:
                        new_cost = cost + weight
                        new_path = path + [neighbor]
                        queue.append((new_cost, neighbor, new_path))
                queue.sort()

        return "No path found", float('inf')

if __name__ == "__main__":
    graph = {}
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        u, v, weight = input("Enter edge (node neighbor weight): ").split()
        if u not in graph:
            graph[u] = {}
        graph[u][v] = int(weight)

    g = Graph(graph)
    start_node = input("Enter start node: ")
    goal_node = input("Enter goal node: ")
    best_path, min_cost = g.ucs(start_node, goal_node)

    print("Best Path:", best_path)
    print("Minimum Cost:", min_cost)