#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v)) return edge;
            parent[find(u)] = find(v);
        }
        return {};
    }

private:
    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
};
