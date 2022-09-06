// dfs
class Solution {
private:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (l == 0) node->left = nullptr;
        if (r == 0) node->right = nullptr;
        return node->val || l || r;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if (root->val == 0 && !root->left && !root->right) return nullptr;
        return root;
    }
};
