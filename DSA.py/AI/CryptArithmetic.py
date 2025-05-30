from itertools import permutations

def find_solution():
    for perm in permutations(range(10), 8):
        cross = 10000 * perm[0] + 1000 * perm[1] + 100 * perm[2] + 10 * perm[3] + perm[4]
        roads = 10000 * perm[5] + 1000 * perm[6] + 100 * perm[1] + 10 * perm[7] + perm[8]
        danger = 100000 * perm[7] + 10000 * perm[0] + 1000 * perm[3] + 100 * perm[2] + 10 * perm[5] + perm[6]

        if cross + roads == danger:
            return cross, roads, danger

    return None

solution = find_solution()
if solution:
    cross, roads, danger = solution
    print(f"CROSS: {cross}")
    print(f"ROADS: {roads}")
    print(f"DANGER: {danger}")
else:
    print("No solution found.")
