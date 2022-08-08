// preoder
class Solution {
private:
    bool solver(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        return r1 && r2 && r1->val == r2->val && solver(r1->left, r2->right) && solver(r1->right, r2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solver(root->left, root->right);
    }
};
