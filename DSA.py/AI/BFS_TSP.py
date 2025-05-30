class Graph:
    def __init__(self, graph):
        self.graph = graph

    def tsp_bfs(self, start):
        visited = {start}
        queue = [(start, [start], 0)]
        min_cost = float('inf')
        best_path = []

        while queue:
            node, path, cost = queue.pop(0)
            if len(visited) == len(self.graph):
                if node == start and len(path) == len(self.graph) + 1:
                    if cost < min_cost:
                        min_cost = cost
                        best_path = path
            else:
                for neighbor, weight in self.graph[node].items():
                    if neighbor not in visited:
                        new_path = path + [neighbor]
                        new_cost = cost + weight
                        queue.append((neighbor, new_path, new_cost))
                        visited.add(neighbor)

        return best_path, min_cost

if __name__ == "__main__":
    graph = {}
    num_nodes = int(input("Enter the number of nodes: "))
    for i in range(num_nodes):
        node = input(f"Enter node {i+1}: ")
        graph[node] = {}
        num_neighbors = int(input(f"Enter the number of neighbors for node {node}: "))
        for j in range(num_neighbors):
            neighbor, weight = input(f"Enter neighbor {j+1} and its weight separated by space: ").split()
            graph[node][neighbor] = int(weight)

    g = Graph(graph)
    start_node = input("Enter the start node: ")
    best_path, min_cost = g.tsp_bfs(start_node)

    print("Best Path:", best_path)
    print("Minimum Cost:", min_cost)