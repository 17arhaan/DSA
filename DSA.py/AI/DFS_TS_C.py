class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v, weight):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append((v, weight))

    def topological_sort(self):
        visited = set()
        stack = []
        node_costs = {}  

        def dfs(node):
            visited.add(node)
            if node in self.graph:
                for neighbor, weight in self.graph[node]:
                    if neighbor not in visited:
                        dfs(neighbor)
                        node_costs[node] = max(node_costs.get(node, 0), weight + node_costs.get(neighbor, 0))
            stack.append(node)

        for node in self.graph:
            if node not in visited:
                dfs(node)

        return stack[::-1], node_costs

    def calculate_cost(self, start, end):
        sorted_order, node_costs = self.topological_sort()
        if start not in node_costs or end not in node_costs:
            return "Start or end node not found in graph."
        if start == end:
            return 0
        max_cost = 0
        for node in sorted_order:
            if node == start:
                max_cost = max(max_cost, node_costs[node])
            if node == end:
                return max_cost

if __name__ == "__main__":
    g = Graph()
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        u, v, weight = input("Enter edge (node neighbor weight): ").split()
        g.add_edge(u, v, int(weight))

    start_node = input("Enter start node: ")
    end_node = input("Enter end node: ")
    cost = g.calculate_cost(start_node, end_node)
    print(f"Cost of going from {start_node} to {end_node} is {cost})