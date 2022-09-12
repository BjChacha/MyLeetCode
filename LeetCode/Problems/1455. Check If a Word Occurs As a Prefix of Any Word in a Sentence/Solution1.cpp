// simulation
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int idx = 1;
        while (ss >> word) {
            if (word.find(searchWord) == 0) return idx;
            idx ++;
        }
        return -1;
    }
};
