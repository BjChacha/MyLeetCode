class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res;
        vector<TreeNode*> cur = {root};
        vector<TreeNode*> nex;
        while (!cur.empty()) {
            res = 0;
            for (const auto& node: cur) {
                res += node->val;
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            cur = nex;
            nex = {};
        }
        return res;
    }
};
