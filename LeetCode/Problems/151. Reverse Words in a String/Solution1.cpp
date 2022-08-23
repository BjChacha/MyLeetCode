// simulation
class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        vector<string> words;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (word.size() > 0) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (word.size()) words.push_back(word);
        string res = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            res += words[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};
