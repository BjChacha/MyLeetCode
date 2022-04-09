// Binary search (left & right)
class Solution {
private:
    int biSearchLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    int biSearchRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
public:
    int search(vector<int>& nums, int target) {
        return biSearchRight(nums, target) - biSearchLeft(nums, target);
    }
};