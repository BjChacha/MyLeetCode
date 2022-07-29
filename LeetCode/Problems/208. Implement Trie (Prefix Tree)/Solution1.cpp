// Trie
class TrieNode {
public:
    bool isLeaf;
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));
        isLeaf = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (const auto& c: word) {
            if (!cur->next[c-'a']) cur->next[c-'a'] = new TrieNode();
            cur = cur->next[c-'a'];
        }
        cur->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (const auto& c: word) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        } 
        return cur->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (const auto& c: prefix) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        } 
        return true;
    }
};