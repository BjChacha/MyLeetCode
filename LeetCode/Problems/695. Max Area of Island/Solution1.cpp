// dfs
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            int up = i - 1 >= 0 && grid[i-1][j] == 1 ? dfs(grid, i - 1, j) : 0;
            int bottom = i + 1 < grid.size() && grid[i+1][j] == 1 ? dfs(grid, i + 1, j) : 0; 
            int left = j - 1 >= 0 && grid[i][j-1] == 1 ? dfs(grid, i, j - 1) : 0; 
            int right = j + 1 < grid[i].size() && grid[i][j+1] == 1 ? dfs(grid, i, j + 1) : 0; 
            return up + bottom + left + right + 1;
        } else {
            return 0;
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};