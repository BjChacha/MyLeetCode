// hash table
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto& num: nums) {
            if (counter.count(num) == 0) counter[num] = 1;
            else counter[num] ++;
        }
        int res = 0;
        if (k == 0) {
            for (auto& p : counter) {
                if (p.second >= 2) res += 1;
            }
        } else {
            for (auto& p : counter) {
                if (counter.count(p.first - k)) res += 1;
                if (counter.count(p.first + k)) res += 1;
            }
            res /= 2;
        }
        return res;
    }
};