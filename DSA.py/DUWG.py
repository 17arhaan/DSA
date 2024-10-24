#Directed Unweighted Graph
class Graph:
    def __init__(self) :
        self.graph = {}

    def add_edge(self,u,v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)

    def display(self):
        result = " "
        for node in self.graph:
            for neighbor in self.graph[node]:
                result += f"({node} --> {neighbor})\n"
        return result.strip()

if __name__ == "__main__":    
    g = Graph()
    print("MENU\nEnter an edge [Format Node Vertice]\nor\nType done to finish" )
    while True:
        edge_input = input("Enter Input: ")
        if edge_input.lower() == "done":
            break
        u,v = map(int , edge_input.split())
        g.add_edge(u,v)
    
    print("The graph is ---->")
    print("\n"+g.display()+"\n")