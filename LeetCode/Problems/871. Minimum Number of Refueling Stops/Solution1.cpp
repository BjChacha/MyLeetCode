// dp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int n = stations.size();
        long dp[n+1];
        memset(dp, 0, (n + 1) * sizeof(long));
        dp[0] = startFuel;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] >= stations[i][0]) dp[j+1] = max(dp[j+1], dp[j] + (long)stations[i][1]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};
