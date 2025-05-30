graph = {
    'A': [('B', 5), ('C', 8), ('D', 6)],
    'B': [('E', 3)],
    'C': [('E', 2), ('F', 4)],
    'D': [('G', 5)],
    'E': [('H', 7), ('I', 6)],
    'F': [('I', 8), ('J', 9)],
    'G': [('H', 4)],
    'H': [('J', 3)],
    'I': [('J', 2)],
    'J': []
}

heuristic = {
    'A': 9,
    'B': 8,
    'C': 7,
    'D': 6,
    'E': 5,
    'F': 6,
    'G': 5,
    'H': 4,
    'I': 3,
    'J': 0
}

def astar(start, goal):
    open_list = [(0, start)]
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic[start]
    came_from = {}

    while open_list:
        current_f, current = min(open_list)

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        open_list.remove((current_f, current))

        for neighbor, cost in graph[current]:
            tentative_g_score = g_score[current] + cost
            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic[neighbor]
                open_list.append((f_score[neighbor], neighbor))

    return None

start_node = input("Enter the start node: ")
goal_node = input("Enter the goal node: ")

path = astar(start_node, goal_node)
if path:
    print("Path found:", path)
else:
    print("No path found.")