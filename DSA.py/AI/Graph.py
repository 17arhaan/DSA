class Graph:
    def __init__ (self):
        self.graph = {}
    def add_edge (self,u,v,w):
        if w < 0:
            raise ValueError("Negative Value")
        if u not in self.graph:
            self.graph[u] = {}
        self.graph[u][v] = w
    def display(self):
        result = ""
        for node in self.graph:
            for neighbor , w in self.graph[node].items():
                result += f"{node} ---> {neighbor} , Weight : {w} \n"
        return result.strip()
if __name__ == "__main__":
    g = Graph()
    print("bullshit")
    while True:
        edge_input = input("Enter Edge: ")
        if edge_input.lower() == "done":
            break
        try:
            u,v,w = edge_input.split()
            g.add_edge(u,v,int(w))
        except ValueError as e:
            print("Error ",e)
    print(g.display())