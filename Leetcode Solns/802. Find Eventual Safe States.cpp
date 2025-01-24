class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int neighbor : reverseGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
