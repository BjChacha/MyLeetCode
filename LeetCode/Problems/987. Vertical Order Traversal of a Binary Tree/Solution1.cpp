// dfs
class Solution {
private:
    void dfs(TreeNode* node, unordered_map<int, vector<pair<int, int>>>& d, int layer, int pos, int& lo, int& hi) {
        if (!node) return ;
        d[pos].push_back({layer, node->val});
        lo = min(lo, pos);
        hi = max(hi, pos);
        dfs(node->left, d, layer + 1, pos - 1, lo, hi);
        dfs(node->right, d, layer + 1, pos + 1, lo, hi);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> d;
        int lo = 0, hi = 0;
        dfs(root, d, 0, 0, lo, hi);
        for (int i = lo; i <= hi; ++i) {
            if (d.count(i)) {
                vector<int> tmp;
                sort(d[i].begin(), d[i].end());
                for (const auto& p: d[i]) 
                    tmp.push_back(p.second);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
