// slide window
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> memo;
        int res = 0, sm = 0, l = 0, tmp;
        for (int r = 0; r < nums.size(); ++r) {
            if (memo.count(nums[r]) > 0) {
                tmp = memo[nums[r]];
                while (l <= tmp) sm -= nums[l++];
            }
            sm += nums[r];
            res = max(res, sm);
            memo[nums[r]] = r;
        }
        return res;
    }
};