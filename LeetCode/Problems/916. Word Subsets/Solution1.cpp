// Counter
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int cnt[26]{0};
        int tmp[26]{0};
        // 1. integrate all word in words2 into one counter
        for (const auto& w: words2) {
            for (const auto& c: w) {
                tmp[c-'a'] ++;
                cnt[c-'a'] = max(cnt[c-'a'], tmp[c-'a']);
            }
            memset(tmp, 0, 104);
        }
        // 2. check if each word in words1 is valid
        for (const auto& w: words1) {
            copy(begin(cnt), end(cnt), begin(tmp));
            for (const auto& c: w) tmp[c-'a'] --;
            int i = 0;
            while (i < 26) {
                if (tmp[i++] > 0) break;
            }
            if (i == 26) res.push_back(w);
        }
        return res;
    }
};