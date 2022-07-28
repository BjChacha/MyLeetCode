// Counter
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int counter[26]{0};
        for (const auto&c: s) counter[c-'a'] ++;
        for (const auto&c: t) {
            if (counter[c-'a'] == 0) return false;
            counter[c-'a'] --;
        }
        return true;
    }
};