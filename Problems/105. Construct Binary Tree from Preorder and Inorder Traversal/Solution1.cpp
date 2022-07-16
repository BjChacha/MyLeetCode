// recursion
class Solution {
private:
    int preIndex;
    TreeNode* solver(vector<int>& preorder, vector<int>& inorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int i = inLeft;
        while (inorder[i] != preorder[preIndex]) ++i;
        TreeNode* cur = new TreeNode(preorder[preIndex++]);
        cur->left = solver(preorder, inorder, inLeft, i - 1);
        cur->right = solver(preorder, inorder, i + 1, inRight);
        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return solver(preorder, inorder, 0, inorder.size() - 1 );
    }
};