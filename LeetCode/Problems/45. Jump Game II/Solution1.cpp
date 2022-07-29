// dp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int end = 0, res = 0, tmp, i = 0;
        while (i < n) {
            tmp = end;
            for (int j = i; j <= end; ++j) {
                tmp = max(tmp, nums[j] + j);
            }
            ++res;
            if (tmp >= n - 1) return res;
            i = end + 1;
            end = tmp;
        }
        return res;
    }
};