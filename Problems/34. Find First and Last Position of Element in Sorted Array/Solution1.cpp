// binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findLeft(nums, target), findRight(nums, target)};
    }
private:
    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return left < nums.size() && nums[left] == target ? left : -1;
    }
    
    int findRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return right < nums.size() && nums[right] == target ? right : -1;
    }
};