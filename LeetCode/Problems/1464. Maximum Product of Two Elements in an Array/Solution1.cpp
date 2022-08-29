// bruce
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return res;
    }
};
