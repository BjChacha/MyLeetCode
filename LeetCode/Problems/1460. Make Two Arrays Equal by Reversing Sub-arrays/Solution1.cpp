// counter
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnt[1000] {0};
        for (const auto& num: target) cnt[num-1] ++;
        for (const auto& num: arr) {
            if (cnt[num-1] == 0) return false;
            cnt[num-1] --;
        }
        return true;
    }
};
