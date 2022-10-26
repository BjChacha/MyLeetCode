// dfs + bfs
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        const vector<int> dirs = {0, 1, 0, -1 ,0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int,int>> cur;
        vector<pair<int,int>> nex;
        deque<pair<int,int>> reg;
        // 1. 找到其中一个区域的一个点
        bool found = false;
        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    reg.push_back({i, j});
                    found = true;
                    break;
                }
            }
        }
        // 2. 通过dfs从点扩散遍历完一个区域
        while (reg.size()) {
            auto p = reg.front();
            reg.pop_front();
            // 判断是否为边缘点
            bool isEdge = false;
            // 遍历周边四点
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dirs[i], y = p.second + dirs[i+1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    if (grid[x][y] == 1) {
                        vis[x][y] = true;
                        reg.push_back({x, y});
                    } else {
                        isEdge = true;
                    }
                }
            }
            if (isEdge) cur.push_back(p);
        }
        // 3. 从edge点出发，bfs直至碰及grid为1但未被遍历的点
        int res = -1;
        found = false;
        while (!found && cur.size()) {
            ++res;
            for (auto p: cur) {
                if (found) break;
                for (int i = 0; i < 4; ++i) {
                    int x = p.first + dirs[i], y = p.second + dirs[i+1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        if (grid[x][y] == 1) {
                            found = true;
                            break;
                        } else {
                            vis[x][y] = true;
                            nex.push_back({x, y});
                        }
                    }
                }
            }
            cur = nex;
            nex = {};
        }
        return res;
    }
};
