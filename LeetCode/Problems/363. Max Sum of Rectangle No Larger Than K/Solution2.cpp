// prefix sum + binary search
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
        for (int top = 0; top < m; ++top) {
            for (int bot = top + 1; bot <= m; ++bot) {
                set<int> s;
                s.insert(0);
                for (int right = 1; right <= n; ++right) {
                    tmp = acc[bot][right] - acc[top][right];
                    auto it = s.lower_bound(tmp - k);
                    if (it != s.end()) res = max(res, tmp - *it);
                    s.insert(tmp);
                }
            }
        }
        return res;
    }
};
