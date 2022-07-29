// greedy
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = count(s.begin(), s.end(), '0');
        int n = s.length();
        for (int i = 0; i < n && pow(2, i) <= k; ++i) {
            if (s[n-i-1] == '1') {
                res ++;
                k -= pow(2, i);
            }
        }
        return res;
    }
};