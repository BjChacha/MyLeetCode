// dp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]), tmp;
        for (int i = 2; i < nums.size(); ++i) {
            tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
};