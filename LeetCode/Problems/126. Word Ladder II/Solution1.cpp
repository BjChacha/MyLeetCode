class Solution {
private:
    //存放最短路径
    unordered_map<string, int> table;
    //存放通过相邻单词创建的有向图
    unordered_map<string, unordered_set<string>> graph;
    vector<vector<string>> ret;
    //存储回溯算法中的单条路径，用来加入ret，其中元素的顺序为倒序（从endWord到beginWord）
    vector<string> path;
    //用全局变量存储beginWord，减少传参个数
    string target;
public:
    //思路：BFS找最短路同时建图存储节点信息+DFS回溯算法找到所有命中起终点的最短路径
    void dfs(string s){
        //回溯算法模版直接套用
        if(s == target){
            //因为path中元素为倒序，所以想要颠倒过来需要用rbegin, rend
            ret.emplace_back(path.rbegin(), path.rend());
            return;
        }
        for(auto node: graph[s]){
            path.emplace_back(node);
            dfs(node);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //由单词表创建哈希set减少查找的时间复杂度
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> q;
        q.emplace(beginWord);
        //在开始需要给beginWord设置初值0
        table[beginWord] = 0;
        int n = beginWord.size();
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            //对每个单词的每个字母进行循环，对每个字母都尝试a-z所有组合，来查找是否符合本题条件
            for(int i = 0; i < n; ++i){
                auto nextWord = p;
                //让p作为当前节点，nextWord作为下一个节点去探索新的字符组合
                for(auto c = 'a'; c <= 'z'; ++c){
                    nextWord[i] = c;
                    //对于每一种组合，存在于wordList并且从未遍历过或者跟当前单词相邻（为了找到所有相邻节点）
                    if(set.count(nextWord) && (!table.count(nextWord) || table[nextWord] == table[p] + 1))
                        //graph反向插入，有向边的顺序是从endword到beginword
                        graph[nextWord].emplace(p);
                    //如果是存在于wordList并且从未遍历，那么就在最短路径中添加当前节点的相邻节点信息
                    if(set.count(nextWord) && !table.count(nextWord)){
                        table[nextWord] = table[p] + 1;
                        //如果正好遍历到了endWord，那么就终止循环剪枝
                        if(nextWord == endWord) break;
                        q.emplace(nextWord);
                    }
                }
            }
        }
        //如果没找到，返回空vector
        if(!table.count(endWord))   return ret;
        //开始dfs寻找命中起终点的最短路径，记住要先把endWord加进去（因为需要从尾到头找）
        path.emplace_back(endWord);
        target = beginWord;
        dfs(endWord);
        return ret;
    }
};
