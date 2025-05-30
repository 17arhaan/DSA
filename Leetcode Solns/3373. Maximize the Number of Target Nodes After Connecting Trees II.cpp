class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> g1(n), g2(m);
        for (auto &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        vector<int> col1(n, -1), col2(m, -1);
        dfs(0, -1, 0, g1, col1);
        dfs(0, -1, 0, g2, col2);

        long long T1_even = 0, T1_odd = 0, T2_even = 0, T2_odd = 0;
        for (int c : col1) (c ? T1_odd : T1_even)++;
        for (int c : col2) (c ? T2_odd : T2_even)++;

        long long bestT2 = max(T2_even, T2_odd);

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            long long inside = (col1[i] == 0 ? T1_even : T1_odd);
            ans[i] = static_cast<int>(inside + bestT2);   // ≤ 2·10^5, fits in int
        }
        return ans;
    }

private:
    void dfs(int u, int p, int color,
             const vector<vector<int>>& g, vector<int>& col) {
        col[u] = color;
        for (int v : g[u]) if (v != p) dfs(v, u, color ^ 1, g, col);
    }
};
