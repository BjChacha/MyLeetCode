// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sm = nums[0], res = sm;
        for (int i = 1; i < nums.size(); ++i) {
            sm = max(sm + nums[i], nums[i]);
            res = max(res, sm);
        }
        return res;
    }
};
