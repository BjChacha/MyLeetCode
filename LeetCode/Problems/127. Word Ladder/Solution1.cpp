// bfs
class Solution {
private:
    bool isAdjacent(string w1, string w2) {
        int diff = 0;
        for (int i = 0; i < w1.size(); ++i) {
            if (w1[i] != w2[i]) {
                diff ++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        const int n = wordList.size();
        int res = 0;
        vector<string> cur = {beginWord};
        vector<string> nex;
        vector<bool> visited(n, false);

        while (cur.size()) {
            res ++;
            for (const auto& w: cur) {
                if (w == endWord) return res;
                for (int i = 0; i < n; ++i) {
                    if (!visited[i] && isAdjacent(w, wordList[i])) {
                        nex.push_back(wordList[i]);
                        visited[i] = true;
                    }
                }
            }
            cur = nex;
            nex = {};
        }
        return 0;
    }
};
