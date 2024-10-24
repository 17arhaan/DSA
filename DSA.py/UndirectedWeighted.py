class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self,u,v,weight):
        if weight < 0 or u < 0 or v < 0:
            raise ValueError("Value Cannot Be Negative")
        if u not in self.graph:
            self.graph[u] = []
        # if u < 0:    
        #     raise ValueError("Node cant be negative")
        
        self.graph[u].append((v,weight))

    def display(self):
        result = ""
        for node in self.graph:
            for neighbor,weight in self.graph[node]:
                else:
                    result += f"({node} ~ {neighbor} , Weight : {weight})\n"
        return result.strip()

if __name__ == "__main__":
    g = Graph()
    print("\n\t~~~~ MENU ~~~~\n\nEnter an edge [FORMAT : Node Vertice Weight]\n\tor \nType done to finish\n" )
    while True:
        edge_input = input("Enter Input: ")
        if edge_input == "done":
            break
        try:
            u,v,weight = map(int,edge_input.split())
            g.add_edge(u,v,weight)
        except ValueError as e:
            print("Error : ",e)
    
    print("\n",g.display(),"\n")