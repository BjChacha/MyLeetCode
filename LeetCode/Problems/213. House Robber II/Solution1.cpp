// dp
class Solution {
private:
    int solver(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        int first = nums[lo], second = max(nums[lo], nums[lo+1]), tmp;
        for (int i = lo + 2; i <= hi; ++i) {
            tmp = second;
            second = max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(solver(nums, 0, nums.size() - 2), solver(nums, 1, nums.size() - 1));
    }
};