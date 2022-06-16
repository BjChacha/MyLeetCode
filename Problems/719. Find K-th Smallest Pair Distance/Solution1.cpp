// binary search
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = 1000000, mi, cnt, n = nums.size();
        while (lo < hi) {
            mi = lo + (hi - lo >> 1);
            cnt = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mi) ++j;
                cnt += j - i - 1;
            }
            if (cnt >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};