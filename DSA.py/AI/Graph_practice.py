class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self,u,v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)

    def display(self):
        result = " "
        for node in self.graph:
            for neighbor in self.graph[node]:
                result += f"({node} ---> {neighbor})\n"
        return result.strip()
if __name__ == "__main__":
    g = Graph()
    print("FORMAT [node neighbor]")
    while True:
        edge_input = input("Enter Edge: ")
        if edge_input == "done":
            break
        u , v = map(int,edge_input.split())
        g.add_edge(u,v)
    print(g.display())