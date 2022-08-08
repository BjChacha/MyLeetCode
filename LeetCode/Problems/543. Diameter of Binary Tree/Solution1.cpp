// post-order
class Solution {
private:
    int res;
    int solver(TreeNode* node) {
        if (!node) return -1;
        int left = 1 + solver(node->left);
        int right = 1 + solver(node->right);
        res = max(res, left + right);
        return max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        solver(root);
        return res;
    }
};
