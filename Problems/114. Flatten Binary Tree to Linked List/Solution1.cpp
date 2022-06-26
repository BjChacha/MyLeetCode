// recurse
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root) {
            if (root->left) {
                TreeNode* t = root->left;
                while (t->right) t = t->right;
                t->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            flatten(root->right);
        }
        return;
    }
};