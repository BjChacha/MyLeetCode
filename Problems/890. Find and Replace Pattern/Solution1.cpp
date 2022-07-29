class Solution {
private:
    bool compare(string a, string b) {
        unordered_map<char, char> matcher;
        bool seen[26] {false};
        for (int i = 0; i < a.length(); ++i) {
            if (matcher.count(a[i]) == 0) {
                if (seen[b[i]-'a']) return false;
                matcher[a[i]] = b[i];
            } else {
                if (matcher[a[i]] != b[i]) return false;
            }
            seen[b[i]-'a'] = true;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const auto& w: words) 
            if (compare(w, pattern)) res.push_back(w);
        return res;
    }
};