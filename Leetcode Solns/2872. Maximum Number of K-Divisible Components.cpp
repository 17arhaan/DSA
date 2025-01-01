class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long subtreeSum = values[node];

            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    subtreeSum += dfs(neighbor, node);
                }
            }

            if (subtreeSum % k == 0) {
                components++;
                return 0;
            }

            return subtreeSum;
        };

        dfs(0, -1);

        return components;
    }
};
