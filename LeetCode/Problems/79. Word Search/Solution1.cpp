// backtracking
class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& seen, string& word, int i, int j, int k) {
        if (board[i][j] != word[k]) return false;
        else if (k == word.length() - 1) return true; 
        else {
            seen[i][j] = true;
            int m = board.size(), n = board[0].size();
            int dir[5] = {1, 0, -1, 0, 1};

            for (int l = 0; l < 4; ++l) {
                int x = i + dir[l], y = j + dir[l+1];
                if (0 <= x && x < m && 0 <= y && y < n && !seen[x][y]) {
                    if (dfs(board, seen, word, x, y, k + 1)) return true;
                }
            }
            seen[i][j] = false;
            return false;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, seen, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};