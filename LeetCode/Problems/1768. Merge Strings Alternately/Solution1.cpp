class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, n = max(word1.size(), word2.size());
        while (i < n) {
            if (i < word1.size()) res += word1[i];
            if (i < word2.size()) res += word2[i];
            ++i;
        }
        return res;
    }
};
