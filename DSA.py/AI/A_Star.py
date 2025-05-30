class Graph:
    def __init__(self, graph):
        self.graph = graph

    def heuristic(self, node, goal):
        x1, y1 = node
        x2, y2 = goal
        return abs(x1 - x2) + abs(y1 - y2)

    def astar(self, start, goal):
        open_set = {start}
        came_from = {}
        g_score = {node: float('inf') for node in self.graph}
        g_score[start] = 0
        f_score = {node: float('inf') for node in self.graph}
        f_score[start] = self.heuristic(start, goal)

        while open_set:
            current = min(open_set, key=lambda node: f_score[node])
            if current == goal:
                path = []
                while current in came_from:
                    path.append(current)
                    current = came_from[current]
                path.append(start)
                path.reverse()
                return path
            open_set.remove(current)
            for neighbor in self.graph[current]:
                tentative_g_score = g_score[current] + self.graph[current][neighbor]
                if tentative_g_score < g_score[neighbor]:
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g_score
                    f_score[neighbor] = tentative_g_score + self.heuristic(neighbor, goal)
                    if neighbor not in open_set:
                        open_set.add(neighbor)
        return None

if __name__ == "__main__":
    graph = {}
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        x1, y1, x2, y2, weight = map(int, input("Enter edge (x1 y1 x2 y2 weight): ").split())
        node1 = (x1, y1)
        node2 = (x2, y2)
        if node1 not in graph:
            graph[node1] = {}
        if node2 not in graph:
            graph[node2] = {}
        graph[node1][node2] = weight
        graph[node2][node1] = weight

    g = Graph(graph)
    start_node = tuple(map(int, input("Enter start node (x y): ").split()))
    goal_node = tuple(map(int, input("Enter goal node (x y): ").split()))
    path = g.astar(start_node, goal_node)

    if path:
        print("Path found:", path)
    else:
        print("No path found")
