class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) 
            return 0;
        int fish = grid[x][y];
        grid[x][y] = 0;
        fish += dfs(grid, x + 1, y);
        fish += dfs(grid, x - 1, y);
        fish += dfs(grid, x, y + 1);
        fish += dfs(grid, x, y - 1);
        return fish;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int max_fish = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) {
                    max_fish = max(max_fish, dfs(grid, i, j));
                }
            }
        }
        return max_fish;
    }
};