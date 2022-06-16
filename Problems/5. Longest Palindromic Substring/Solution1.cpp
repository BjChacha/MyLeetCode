// two pointers
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0, i = 0, l, r;
        while (i < s.length() - (maxLen + 1) / 2) {
            l = r = i;
            while (r + 1 < s.length() && s[r+1] == s[r]) ++r;
            i = r + 1;
            while (l - 1 >= 0 && r + 1 < s.length() && s[l-1] == s[r+1]) --l, ++r;
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            
        }
        return s.substr(start, maxLen);
    }
};