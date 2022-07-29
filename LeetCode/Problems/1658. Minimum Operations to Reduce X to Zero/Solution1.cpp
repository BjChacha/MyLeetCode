// two pointers
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0, right = nums.size() - 1, res = nums.size() + 1, len;
        long long sm = nums[0];
        while (left + 1 < nums.size() && sm + nums[left+1] <= x) sm += nums[++left];
        
        if (sm == x) res = min(res, left + 1);

        while (left >= 0) {
            // 如果右端加不进去，左端回退
            while (left >= 0 && sm + nums[right] > x) sm -= nums[left--];
            // 加入右端元素
            while (left < right && sm + nums[right] <= x) sm += nums[right--];
            if (sm == x) {
                len = nums.size() + left - right;
                res = min(res, len);
            } else if (left == right) return -1;
        }
        return res > nums.size() ? -1 : res;
    }
};