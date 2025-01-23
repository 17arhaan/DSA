class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int currHeight = height[i][j];
            
            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && height[ni][nj] == -1) {
                    height[ni][nj] = currHeight + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return height;
    }
};