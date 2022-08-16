class Solution {
private:
    unordered_map<string, int> table;
    unordered_map<string, unordered_set<string>> graph;
    vector<vector<string>> res;
    vector<string> path;
    string target;

    void dfs(string cur) {
        if (cur == target) {
            res.emplace_back(path.rbegin(),  path.rend());
        } else {
            for (const auto& nex: graph[cur]) {
                path.emplace_back(nex);
                dfs(nex);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};

        int n = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.emplace(beginWord);
        table[beginWord] = 0;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < n; ++i) {
                auto tmp = p;
                for (auto c = 'a'; c <= 'z'; ++c) {
                    if (p[i] == c) continue;
                    tmp[i] = c;
                    if (wordSet.count(tmp)) {
                        if (!table.count(tmp) || table[tmp] == table[p] + 1) {
                            graph[tmp].emplace(p);
                            if (!table.count(tmp)) {
                                table[tmp] = table[p] + 1;
                                if (tmp == endWord) break;
                                q.emplace(tmp);
                            }
                        }
                    }
                }
            }
        }
        
        path.emplace_back(endWord);
        target = beginWord;
        dfs(endWord);
        return res;
    }
};
