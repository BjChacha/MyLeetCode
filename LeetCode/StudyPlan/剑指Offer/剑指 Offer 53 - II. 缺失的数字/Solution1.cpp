// Binary search
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] > mid) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};