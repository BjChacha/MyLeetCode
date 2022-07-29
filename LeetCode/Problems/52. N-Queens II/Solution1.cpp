// backtracking
class Solution {
private:
    int res;
    void dfs(vector<vector<int>>& mat, int i) {
        if (i == mat.size()) {
            ++res;
        }
        else {
            for (int j = 0; j < mat[i].size(); ++j) {
                if (isValid(mat, i, j)) {
                    mat[i][j] = 1;
                    dfs(mat, i + 1);
                    mat[i][j] = 0;
                }
            }
        }
    }
    
    bool isValid(vector<vector<int>>& mat, int i, int j) {
        if (mat[i][j] == 1) return false;
        for (int x = 0; x < mat.size(); ++x) {
            if (mat[x][j] == 1) return false;
        }
        for (int x = 0; i - x >= 0 && j - x >= 0; ++x) {
            if (mat[i-x][j-x] == 1) return false;
        }
        for (int x = 0; i - x >= 0 && j + x < mat[0].size(); ++x) {
            if (mat[i-x][j+x] == 1) return false;
        }
        return true;
    }
    
    
public:
    int totalNQueens(int n) {
        res = 0;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        dfs(mat, 0);
        return res;
    }
};