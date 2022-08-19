// Counter
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (const auto& a: arr) counter[a] = counter.count(a) ? counter[a] + 1 : 1;
        vector<int> sorted;
        for (const auto& p: counter) sorted.push_back(p.second);
        sort(sorted.begin(), sorted.end(), greater<int>());
        int res = 0, cnt = 0, n = arr.size();
        for (const auto& a: sorted) {
            if (cnt >= n / 2) break;
            cnt += a;
            res += 1;
        }
        return res;
    }
};
