// memorization
class Solution {
private:
    int cache[50][50][50];
    int dfs(vector<vector<int>>& grid, int x1, int y1, int x2) {
        int y2 = x1 + y1 - x2;
        int n = grid.size();
        if (x1 == n || y1 == n || x2 == n || y2 == n || grid[x1][y1] == -1 || grid[x2][y2] == -1) return INT_MIN;
        if (x1 == x2 && x1 == n - 1 && y1 == n - 1) return grid[x1][y1];
        
        if (cache[x1][y1][x2] == 0) {
            cache[x1][y1][x2] = grid[x1][y1] + (x1 == x2 ? 0 : grid[x2][y2]) + max(
                max(dfs(grid, x1 + 1, y1, x2 + 1), dfs(grid, x1 + 1, y1, x2)),
                max(dfs(grid, x1, y1 + 1, x2 + 1), dfs(grid, x1, y1 + 1, x2))
            );
        }
        return cache[x1][y1][x2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int res = dfs(grid, 0, 0, 0);
        return res < 0 ? 0 : res;
    }
};
