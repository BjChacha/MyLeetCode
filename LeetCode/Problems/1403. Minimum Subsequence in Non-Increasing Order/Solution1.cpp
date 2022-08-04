// Greedy
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        int sm = 0;
        sort(nums.begin(), nums.end(), [&](int a, int b) {return a > b;});
        for (const auto& num: nums) sm += num;
        sm /= 2;
        for (const auto& num: nums) {
            res.push_back(num);
            sm -= num;
            if (sm < 0) break;
        }
        return res;
    }
};
