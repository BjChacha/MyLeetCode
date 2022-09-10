// dfs 
class Solution {
private:
    void dfs(TreeNode* node, int preMax, int& res) {
        if (!node) return;
        if (node->val >= preMax) res ++;
        dfs(node->left, max(preMax, node->val), res);
        dfs(node->right, max(preMax, node->val), res);
    }
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};
