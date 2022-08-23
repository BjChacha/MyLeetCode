// level order
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        vector<TreeNode*> cur{root};
        vector<TreeNode*> nex;
        while (cur.size()) {
            for (const auto& node: cur) {
                tmp.push_back(node->val);
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            res.push_back(tmp);
            cur = nex;
            nex = {};
            tmp = {};
        }
        return res;
    }
};
