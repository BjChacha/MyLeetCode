// binary search (STL)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {left < nums.size() && nums[left] == target ? left : -1, right < nums.size() && nums[right] == target ? right : -1};
    }
};