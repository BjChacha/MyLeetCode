class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // 求最小rob方案中house的最大价值
        int lo = 0, hi = *max_element(nums.begin(), nums.end()), mi;
        int f1, f2, tmp, cnt;
        while (lo < hi) {
            mi = lo + ((hi - lo) >> 1);
            f1 = f2 = 0;
            for (int& num: nums) {
                // 以num为capability，模拟k次rob的结果
                if (num > mi) {
                    // 大于capability的house不能进行rob，skip掉
                    f2 = f1;
                } else {
                    // 能进行rob
                    tmp = f1;
                    f1 = max(f2 + 1, f1);
                    f2 = tmp;
                }
            }

            if (f1 < k) {
                // 能rob的house数量小于k，说明capability太小
                lo = mi + 1;
            } else {
                // 能rob的house数量小于k，说明capability可能是最优解，左移右边界来寻找最小值
                hi = mi;
            }
        }
        return lo;
    }
};
