// inorder
class Solution {
private:
    void inorder(vector<int>& nums, TreeNode* node) {
        if (node) {
            inorder(nums, node->left);
            nums.push_back(node->val);
            inorder(nums, node->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inorder(nums, root);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};
