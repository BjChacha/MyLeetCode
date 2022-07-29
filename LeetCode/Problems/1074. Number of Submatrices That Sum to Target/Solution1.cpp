// Prefix Sum
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> accu(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) accu[i+1][j+1] += matrix[i][j] + accu[i+1][j];
                else accu[i+1][j+1] += matrix[i][j] + accu[i][j+1] + accu[i+1][j] - accu[i][j];
            }
        }
        int res = 0;
        for (int u = 0; u < m; ++u) {
            for (int b = u; b < m; ++b) {
                for (int l = 0; l < n; ++l) {
                    for (int r = l; r < n; ++r) {
                        int sum = accu[b+1][r+1] - accu[b+1][l] - accu[u][r+1] + accu[u][l];
                        if (sum == target) res ++;
                    }
                }
            }
        }
        return res;
    }
};