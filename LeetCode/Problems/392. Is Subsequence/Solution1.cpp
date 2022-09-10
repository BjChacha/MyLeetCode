// two pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, n = s.size();
        if (n == 0) return true;
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                ++i;
                if (i == n) return true;
            }
        }
        return false;
    }
};
