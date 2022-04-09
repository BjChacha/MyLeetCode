// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.size(), m = needle.size();
        // 1. build next
        vector<int> next(m, -1);
        int i = 0, j = -1;
        while (i < m - 1) {
            if (j == -1 || needle[i] == needle[j]) next[++i] = ++j;
            else j = next[j];
        }
        // 2. match
        i = 0, j = 0;
        while (i < n && j < m) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i,++j;
                if (j == m) return i - j;
            } else {
                j = next[j];
            }
        }
        return -1;
    }
};