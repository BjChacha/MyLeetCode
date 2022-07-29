// loop
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> cur;
        vector<int> pre(1, 1);
        vector<vector<int>> res{pre};
        for (int i = 1; i < numRows; ++i) {
            cur = {1};
            for (int j = 1; j < pre.size(); ++j) 
                cur.push_back(pre[j-1]+pre[j]);
            cur.push_back(1);
            res.push_back(cur);
            pre = cur;
        }
        return res;
    }
};