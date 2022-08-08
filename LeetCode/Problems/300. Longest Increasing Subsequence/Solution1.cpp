// binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2500]{0};
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) 
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
        return res;
    }
};;
