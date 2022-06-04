// backtracking
class Solution {
private:
    void dfs(vector<vector<int>>& mat, vector<vector<string>>& res, int i) {
        if (i == mat.size()) {
            res.push_back(mat2str(mat));
        }
        else {
            for (int j = 0; j < mat[i].size(); ++j) {
                if (isValid(mat, i, j)) {
                    mat[i][j] = 1;
                    dfs(mat, res, i + 1);
                    mat[i][j] = 0;
                }
            }
        }
    }
    
    bool isValid(vector<vector<int>>& mat, int i, int j) {
        if (mat[i][j] == 1) return false;
        for (int x = 0; x < mat[i].size(); ++x) {
            if (mat[i][x] == 1) return false;
        }
        for (int x = 0; x < mat.size(); ++x) {
            if (mat[x][j] == 1) return false;
        }
        for (int x = 0; i - x >= 0 && j - x >= 0; ++x) {
            if (mat[i-x][j-x] == 1) return false;
        }
        for (int x = 0; i + x < mat.size() && j - x >= 0; ++x) {
            if (mat[i+x][j-x] == 1) return false;
        }
        for (int x = 0; i + x < mat.size() && j + x < mat[0].size(); ++x) {
            if (mat[i+x][j+x] == 1) return false;
        }
        for (int x = 0; i - x >= 0 && j + x < mat[0].size(); ++x) {
            if (mat[i-x][j+x] == 1) return false;
        }
        return true;
    }
    
    vector<string> mat2str(vector<vector<int>> mat) {
        vector<string> res;
        for (int i = 0; i < mat.size(); ++i) {
            string tmp = "";
            for (int j = 0; j < mat[0].size(); ++j) {
                tmp += mat[i][j] == 1 ? 'Q' : '.';
            }
            res.push_back(tmp);
        }
        return res;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<string>> res;
        dfs(mat, res, 0);
        return res;
    }
};