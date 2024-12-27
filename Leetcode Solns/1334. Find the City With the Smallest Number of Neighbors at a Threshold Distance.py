class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        INF = float('inf')
        dist = [[INF] * n for _ in range(n)]
        
        for i in range(n):
            dist[i][i] = 0
        
        for u, v, weight in edges:
            dist[u][v] = weight
            dist[v][u] = weight
        
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        
        min_neighbors = n
        city_with_min_neighbors = -1
        
        for i in range(n):
            count = sum(1 for j in range(n) if dist[i][j] <= distanceThreshold)
            
            if count <= min_neighbors:
                min_neighbors = count
                city_with_min_neighbors = i
        
        return city_with_min_neighbors
