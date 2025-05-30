class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2,
                               int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        auto bfsCount = [&](const vector<vector<int>>& adj,
                            int src,
                            int maxDist) {
            if (maxDist < 0) return 0;
            int N = adj.size();
            vector<int> dist(N, -1);
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            int cnt = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                int d = dist[u];
                if (d > maxDist) break;
                ++cnt;
                if (d == maxDist) continue;
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = d + 1;
                        q.push(v);
                    }
                }
            }
            return cnt;
        };
        vector<int> C1(n);
        for (int i = 0; i < n; ++i) {
            C1[i] = bfsCount(adj1, i, k);
        }
        int best2 = 0;
        for (int j = 0; j < m; ++j) {
            best2 = max(best2, bfsCount(adj2, j, k - 1));
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = C1[i] + best2;
        }
        return ans;
    }
};
