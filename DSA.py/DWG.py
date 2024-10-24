#Directed Weighted Graph
class Graph:
    def __init__(self) :
        self.graph = {}

    def add_edge(self,u,v,weight):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append((v,weight))

    def display(self):
        result = " "
        for node in self.graph:
            for neighbor , weight in self.graph[node]:
                    result += f"({node} --> {neighbor} , Weight : {weight})\n"
        return result.strip()

if __name__ == "__main__":    
    g = Graph()
    print("MENU\nEnter an edge [Format Node Vertice Weight]\nor\nType done to finish" )
    while True:
        edge_input = input("Enter Input: ")
        if edge_input.lower() == "done":
            break
        u,v,weight = map(int , edge_input.split())
        g.add_edge(u,v,weight)
    
    print("The graph is ---->")
    print("\n"+g.display()+"\n")