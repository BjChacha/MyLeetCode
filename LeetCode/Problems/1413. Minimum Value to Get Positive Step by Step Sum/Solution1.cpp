class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0, acc = 0;
        for (const auto& num: nums) {
            acc += num;
            res = min(res, acc);
        }
        return -res + 1;
    }
};
