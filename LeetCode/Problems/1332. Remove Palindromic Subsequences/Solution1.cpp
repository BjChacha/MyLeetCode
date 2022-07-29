// two pointers
class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        bool isPalindrome = true;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n-i-1]) {
                isPalindrome = false;
                break;
            }
        }
        return isPalindrome ? 1 : 2;
    }
};