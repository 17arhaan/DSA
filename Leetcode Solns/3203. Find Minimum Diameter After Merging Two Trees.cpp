class Solution {
public:
    vector<int> bfs(int start, int n, vector<vector<int>>& graph, int& farthestNode) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        farthestNode = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[farthestNode]) {
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return dist;
    }
    
    int findDiameter(int n, vector<vector<int>>& edges, vector<int>& centers) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int farthestNode;
        bfs(0, n, graph, farthestNode); // Step 1: Find the farthest node
        vector<int> dist = bfs(farthestNode, n, graph, farthestNode); // Step 2: Find diameter

        int diameter = dist[farthestNode];
        for (int i = 0; i < n; ++i) {
            if (dist[i] == diameter / 2 || dist[i] == (diameter + 1) / 2) {
                centers.push_back(i); // Collect center nodes
            }
        }

        return diameter;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1; // Number of nodes in the first tree
        int m = edges2.size() + 1; // Number of nodes in the second tree

        vector<int> centers1, centers2;

        // Find diameters and centers of both trees
        int diameter1 = findDiameter(n, edges1, centers1);
        int diameter2 = findDiameter(m, edges2, centers2);

        // Try connecting all pairs of centers and find the minimum resulting diameter
        int minDiameter = INT_MAX;
        for (int c1 : centers1) {
            for (int c2 : centers2) {
                int newDiameter = max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
                minDiameter = min(minDiameter, newDiameter);
            }
        }

        return minDiameter;
    }
};
