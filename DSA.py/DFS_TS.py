class Graph:
    def __init__ (self):
        self.graph = {}
    def add_edge(self,u,v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(u)

    def topological_sort(self):
        visited = set()
        stack = []
        
        def dfs(node):
            visited.add(node)
            if node in self.graph:
                for neighbor , _ in sorted (self.graph[node] , key = lambda x : x [1]):
                    if neighbor not in visited:
                        dfs(neighbor)
            stack.append(node)

        for node in self.graph:
            if node not in visited:
                dfs(node)
            
        return stack[::-1]


if __name__ == "__main__":
    g = Graph()
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        u,v = input("Enter the edge [node neighbor ]: ").split()
        g.add_edge(u,v)
    
    sorted_order = g.topological_sort()
    print("Topological Sort ---->")
    print(sorted_order)