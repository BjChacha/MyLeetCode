// Trie
struct Trie{
    vector<int> idx;
    vector<Trie*> c;
    Trie() {
         c = vector<Trie*>(26, nullptr);
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie* head = new Trie();
        Trie* cur = head;
        sort(products.begin(), products.end());
        for (int i = 0; i < products.size(); ++i) {
            for (auto& ch: products[i]) {
                if (!cur->c[ch-'a']) cur->c[ch-'a'] = new Trie();
                cur = cur->c[ch-'a'];
                cur->idx.push_back(i);
            }
            cur = head;
        }
        bool valid = true;
        cur = head;
        for (auto& ch: searchWord) {
            vector<string> tmp;
            if (valid) {
                if (!cur->c[ch-'a']) {
                    valid = false;
                } else {
                    cur = cur->c[ch-'a'];
                    int cnt = 0;
                    
                    for (int i = 0; i < cur->idx.size(); ++i) {
                        tmp.push_back(products[cur->idx[i]]);
                        cnt ++;
                        if (cnt == 3) break;
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};