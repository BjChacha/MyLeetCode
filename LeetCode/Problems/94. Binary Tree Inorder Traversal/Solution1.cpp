// inorder
class Solution {
private:
    void inorder(TreeNode* node, vector<int>& arr) {
        if (node) {
            inorder(node->left, arr);
            arr.push_back(node->val);
            inorder(node->right, arr);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
