class Graph:

    def __init__(self,graph):
        self.graph = graph
    
    def ucs(self,start,goal):
        visited = set()
        queue = [(0 , start , [start])]
        while queue:
            queue.sort()
            cost , node , path = queue.pop(0)
            if node == goal:
                return path , cost
            if node not in visited:
                visited.add(node)
                for neighbor , weight in self.graph[node].items():
                    if neighbor not in visited:
                        new_cost = cost + weight
                        new_path = path + [neighbor]
                        queue.append((new_cost , neighbor , new_path))
        return ("No Path Found..") , float('inf')

if __name__ == "__main__":
    graph = {}
    print("\n\t~~~~ MENU ~~~~\n\nEnter an edge [FORMAT : Node Vertice Weight]\n\tor \nType done to finish\n" )
    while True:
        edge_input = input("Enter Edge: ")
        if edge_input.lower() == "done":
            break
        try:
            u,v,weight = edge_input.split()
            weight = int(weight)
            if weight < 0:
                raise ValueError("Negative Weight")
            if u not in graph:
                graph[u] = {}
            graph[u][v] = weight
        except ValueError as e:
            print("Invalid Input ",e)
    g = Graph(graph)
    start_node = input("Enter Starting Node : ")
    goal_node = input("Enter Goal Node : ")
    best_path,min_cost = g.ucs(start_node,goal_node)

    if best_path == "No Path Found..":
        print(best_path)
    else:
        print("Best Path --->")
        print(best_path)
        print("Minimum Cost: ",min_cost)