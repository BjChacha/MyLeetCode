class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> tmp;
        vector<Node*> cur, nex;
        cur.push_back(root);
        while (cur.size()) {
            tmp = {};
            for (const auto& node: cur) {
                tmp.push_back(node->val);
                for (const auto& child: node->children) {
                    nex.push_back(child);
                }
            }
            res.push_back(tmp);
            cur = nex;
            nex = {};
        } 
        return res;
    }
};
