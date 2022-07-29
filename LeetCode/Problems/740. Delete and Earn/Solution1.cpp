// dp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> counter;
        int mx = 0;
        for (auto& num: nums) {
            mx = max(mx, num);
            if (counter.count(num)) counter[num] += 1;
            else counter[num] = 1;
        }
        int first = counter.count(1) ? counter[1] : 0;
        int second = max(first, counter.count(2) ? 2 * counter[2] : 0), tmp;
        for (int i = 3; i <= mx; ++i) {
            tmp = second;
            second = max(second, first + (counter.count(i) ? i * counter[i] : 0));
            first = tmp;
        }
        return second;
    }
};