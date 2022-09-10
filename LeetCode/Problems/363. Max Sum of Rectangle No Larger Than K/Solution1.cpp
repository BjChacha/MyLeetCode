// prefix sum
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size(), n = matrix[0].size();
        int acc[m+1][n+1];
        for (int i = 0; i <= m; ++i) acc[i][0] = 0;
        for (int j = 0; j <= n; ++j) acc[0][j] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                acc[i+1][j+1] = matrix[i][j] + acc[i+1][j] + acc[i][j+1] - acc[i][j];
            }
        }
        
        int res = INT_MIN, tmp;
        for (int x1 = 0; x1 < m; ++x1) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int x2 = x1 + 1; x2 <= m; ++x2) {
                    for (int y2 = y1 + 1; y2 <= n; ++y2) {
                        tmp = acc[x2][y2] - acc[x2][y1] - acc[x1][y2] + acc[x1][y1];
                        if (tmp <= k) res = max(res, tmp);
                    }
                }
            }
        }
        return res;
    }
};
