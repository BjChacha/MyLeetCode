// hash-table
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int& num: nums) set.insert(num);
        int res = 0, cur, tmp;
        for (int& num: nums) {
            if (set.count(num-1) == 0) {
                cur = num, tmp = 1;
                while (set.count(cur + 1)) {
                    cur += 1;
                    tmp += 1;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};