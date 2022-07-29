// trie + memory search
struct Node {
    vector<int> idx;
    vector<Node*> c;
    Node() :  c(26, nullptr) {}
};

class WordFilter {
private:
    Node* head = new Node();
    Node* tail = new Node();
    unordered_map<string, int> memo;
    
    
    vector<int> getPrefix(string str) {
        Node* cur = head;
        for (auto& ch: str) {
            if (!cur->c[ch-'a']) return {};
            cur = cur->c[ch-'a'];
        }
        return cur->idx;
    }
    
    vector<int> getSuffix(string str) {
        Node* cur = tail;
        for (int i = str.length() - 1; i >= 0; --i) {
            if (!cur->c[str[i]-'a']) return {};
            cur = cur->c[str[i]-'a'];
        }
        return cur->idx;
    }
public:
    WordFilter(vector<string>& words) {
        for (int i = words.size() - 1; i >= 0; --i) {
            Node* cur = head;
            for (auto& ch: words[i]) {
                if (!cur->c[ch-'a']) cur->c[ch-'a'] = new Node();
                cur = cur->c[ch-'a'];
                cur->idx.push_back(i);
            }
            
            cur = tail;
            for (int j = words[i].length() - 1; j >= 0; --j) {
                if (!cur->c[words[i][j]-'a']) cur->c[words[i][j]-'a'] = new Node();
                cur = cur->c[words[i][j]-'a'];
                cur->idx.push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key = prefix + " " + suffix;
        if (memo.count(key) == 0){
            vector<int> a1 = getPrefix(prefix);
            vector<int> a2 = getSuffix(suffix);
            int i1 = 0, i2 = 0, res = -1;
            while (i1 < a1.size() && i2 < a2.size()) {
                if (a1[i1] == a2[i2]) {
                    res = a1[i1];
                    break;
                }
                else if (a1[i1] > a2[i2]) ++i1  ;
                else ++i2;
            }
            memo[key] = res;
        }
        return memo[key];
    }
};