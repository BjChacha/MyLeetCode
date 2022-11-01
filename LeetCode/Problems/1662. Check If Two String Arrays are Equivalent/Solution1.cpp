// simulation
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int a1, a2, b1, b2;
        a1 = a2 = b1 = b2 = 0;
        while (a1 < word1.size()) {
            if (word1[a1][b1] != word2[a2][b2]) return false;
            b1 ++;
            if (b1 >= word1[a1].size()) {
                a1 ++;
                b1 = 0;
            }
            b2 ++;
            if (b2 >= word2[a2].size()) {
                a2 ++;
                b2 = 0;
                if (a2 == word2.size()) return a1 == word1.size();
            }
        }
        return a2 == word2.size();
    }
};
