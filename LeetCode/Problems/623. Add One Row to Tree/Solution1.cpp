class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        
        vector<TreeNode*> cur = {root};
        vector<TreeNode*> nex;
        while (depth-- > 2) {
            for (const auto&  node: cur) {
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            cur = nex;
            nex = {};
        }
        for (auto& node: cur) {
            TreeNode* l = new TreeNode(val, node->left, nullptr);
            TreeNode* r = new TreeNode(val, nullptr, node->right);
            node->left = l;
            node->right = r;
        }
        return root;
    }
};
