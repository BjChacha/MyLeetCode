// hash table
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> set;
        vector<string> mapper = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string tmp;
        for (const auto& w: words) {
            tmp = "";
            for (const auto& c: w) {
                tmp += mapper[c-'a'];
            }
            set.insert(tmp);
        }
        return set.size();
    }
};
