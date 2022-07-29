// dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j  - 1 < 0) triangle[i][j] += triangle[i-1][j];
                else if (j == i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        int res = 1e9;
        for (int i = 0; i < n; ++i) {
            res = min(res, triangle[n-1][i]);
        }
        return res;
    }
};