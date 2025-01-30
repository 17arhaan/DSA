#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, -1);
        function<bool(int)> isBipartite = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = color[node] ^ 1;
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
            return true;
        };

        function<int(int)> bfsMaxDepth = [&](int start) {
            queue<int> q;
            unordered_map<int, int> depth;
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        vector<bool> visited(n + 1, false);
        int maxGroups = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                if (!isBipartite(component[0])) return -1;

                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, bfsMaxDepth(node));
                }
                maxGroups += maxDepth;
            }
        }
        
        return maxGroups;
    }
};
