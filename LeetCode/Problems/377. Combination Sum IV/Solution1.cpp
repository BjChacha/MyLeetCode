// dp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < target; ++i) {
            for (const auto& num: nums) {
                if (i + num <= target && INT_MAX - dp[i] >= dp[i+num]) dp[i+num] += dp[i];
            }
        }       
        return dp[target];
    }
};
