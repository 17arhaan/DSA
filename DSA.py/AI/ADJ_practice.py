class Graph:
    def __init__ (self,vertices):
        self.vertices = vertices
        self.adj_list = [[] for _ in range(vertices)]
        self.adj_matrix = [[0]* vertices for _ in range(vertices)]

    def add_edge(self,u,v):
        if u < 0 or u >= self.vertices or v < 0 or v >= self.vertices:
            print("Invalid Vertices")
            return
        else:
            self.adj_list[u].append(v)
            self.adj_matrix[u][v] = 1

    def display(self):
        print("\nAdjacency List ---->\n")
        for vertex in range(self.vertices):
            print(vertex,"-->",self.adj_list[vertex])
        print("\nAdjacency Matrix ---->\n")
        for row in self.adj_matrix:
            print(row)

if __name__ == "__main__":
    vertices = int(input("Enter the number of vertices: "))
    g = Graph(vertices)
    print("MENU\nEnter an edge [Format Node Vertice]\nor\nType done to finish")
    while True:
        edge_input = input("Enter Edge: ")
        if edge_input == "done":
            break
        u,v = map(int,edge_input.split())
        g.add_edge(u,v)
    g.display()