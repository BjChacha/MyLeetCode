// sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, i = 0, n = nums.size(), j, k;
        while (i < n) {
            j = i, k = 0;
            while (j + 1 < n) {
                if (nums[j+1] == nums[j] + 1) {
                    ++j;
                } else if (nums[j+1] == nums[j]) {
                    ++j;
                    ++k;
                } else {
                    break;
                }
            }
            res = max(res, j - i + 1 - k);
            i = j + 1;
        }
        return res;
    }
};