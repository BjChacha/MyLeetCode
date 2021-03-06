// sort
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, mid = nums[nums.size()/2];
        for (const int& num: nums) res += abs(num - mid);
        return res;
    }
};