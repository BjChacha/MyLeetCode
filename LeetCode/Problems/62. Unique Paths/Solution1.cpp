// dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = i == 0 || j == 0 ? 1 : (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
        return dp[m-1][n-1];
    }
};
