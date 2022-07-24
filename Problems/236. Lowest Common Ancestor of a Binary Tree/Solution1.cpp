// recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root->val == p->val || root->val == q->val ) return root;
        TreeNode* lr = lowestCommonAncestor(root->left, p, q);
        TreeNode* rr = lowestCommonAncestor(root->right, p, q);
        if (lr && rr) return root;
        else return lr ? lr : rr;
    }
};