class Solution {
private:
    bool isAdjacent(string w1, string w2) {
        int diff = 0;
        for (int i = 0; i < w1.length; ++i){
            if (w1[i] != w2[i]) diff ++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int> path(n, -1);
        vector<vector<string>> res;
        vector<string> tmp;
        vector<vector<int>> back(n);

        // 1. 先看endWord在不在wordList中
        bool existed = false;
        for (const string& w: wordList) {
            if (w == endWord) {
                existed = true;
                break;
            }
        }
        if (!existed) return res;

        // 2. bfs
        vector<int> cur;
        vector<int> nex;

        for (int i = 0; i < n; ++i) {
            if (isAdjacent(beginWord, wordList[i])) {
                cur.push_back(i);
                path[i] = 1;
            }
        }

        while (cur.size()) {
            for (const string& w: cur) {
                for (int i = 0; i < n; ++i) {
                    if (path[i] < 0 && isAdjacent(wordList[w], wordList[i])) {
                        nex.push_back(i);
                        path[i] = path[w] + 1;
                    }
                }

            }
        }
    }
};
