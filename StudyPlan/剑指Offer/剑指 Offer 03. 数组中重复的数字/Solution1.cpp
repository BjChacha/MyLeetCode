class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int target;
        for (int i = 0; i < nums.size(); ++i) {
            target = nums[i] < 0 ? - nums[i] - 1 : nums[i];
            if (nums[target] < 0) return target;
            nums[target] = - nums[target] - 1;
        }
        return -1;
    }
};