class Solution {
private:
    bool compare(string a, string b) {
        int matcher[26] {0};
        bool seen[26] {false};
        for (int i = 0; i < a.length(); ++i) {
            if (matcher[a[i]-'a'] == 0) {
                if (seen[b[i]-'a']) return false;
                matcher[a[i]-'a'] = b[i] - 'a' + 1;
            } else {
                if (matcher[a[i]-'a'] != b[i] - 'a' + 1) return false;
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