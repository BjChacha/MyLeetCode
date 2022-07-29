class Solution {
public:
    int minDistance(string word1, string word2) {
        int INF = 501;
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, INF));
        for (int i = 0; i <= word1.length(); ++i) {
            for (int j = 0; j <= word2.length(); ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[word1.length()][word2.length()];
    }
};