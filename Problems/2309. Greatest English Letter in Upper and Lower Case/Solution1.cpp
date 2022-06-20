// hash set
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> set;
        for (char& c: s) set.insert(c);

        for (char c = 'z'; c >= 'a'; c--) {
            if (set.count(c) && set.count(c - 32)) return string(1, c - 32);
        }
        return "";
    }
};