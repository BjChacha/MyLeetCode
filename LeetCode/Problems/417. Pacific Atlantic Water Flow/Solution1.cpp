// dfs
class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& flag, int x, int y, int t) {
        flag[x][y] |= t;
        if (x + 1 < heights.size() && (flag[x+1][y] & t) == 0 && heights[x+1][y] >= heights[x][y]) dfs(heights, flag, x + 1, y, t);
        if (x - 1 >= 0 && (flag[x-1][y] & t) == 0 && heights[x-1][y] >= heights[x][y]) dfs(heights, flag, x - 1, y, t);
        if (y + 1 < heights[0].size() && (flag[x][y+1] & t) == 0 && heights[x][y+1] >= heights[x][y]) dfs(heights, flag, x, y + 1, t);
        if (y - 1 >= 0 && (flag[x][y-1] & t) == 0 && heights[x][y-1] >= heights[x][y]) dfs(heights, flag, x, y - 1, t);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> flag(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(heights, flag, i, 0, 1);
            dfs(heights, flag, i, n - 1, 2);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, flag, 0, j, 1);
            dfs(heights, flag, m - 1, j, 2);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (flag[i][j] == 3) res.push_back({i, j});
            }
        }

        return res;
    }
};
