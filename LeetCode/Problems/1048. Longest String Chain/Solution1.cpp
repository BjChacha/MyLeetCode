// dp
class Solution {
private:
    bool isPredecessor(string& a, string& b) {
        if (a.length() + 1 != b.length()) return false;
        bool missing = false;
        int i = 0, j = 0;
        while (j < b.length()) {
            if (a[i] != b[j]) {
                if (missing) return false;
                else missing = true;
            } else {
                ++i;
            }
            ++j;
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {return a.length() < b.length();});
        int res = 1, n = words.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPredecessor(words[i], words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};