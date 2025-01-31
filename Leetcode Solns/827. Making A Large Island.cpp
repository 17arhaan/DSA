class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(vector<vector<int>>& grid, int r, int c, int islandId) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
        grid[r][c] = islandId;
        int size = 1;
        for (auto& d : directions) {
            size += dfs(grid, r + d[0], c + d[1], islandId);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;
        int islandId = 2, maxIsland = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int size = dfs(grid, r, c, islandId);
                    islandSize[islandId] = size;
                    maxIsland = max(maxIsland, size);
                    islandId++;
                }
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1;
                    for (auto& d : directions) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            seen.insert(grid[nr][nc]);
                        }
                    }
                    for (int id : seen) {
                        newSize += islandSize[id];
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland == 0 ? n * n : maxIsland;
    }
};