// recursion 
class Solution {
private:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int mx = -1, id = -1;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > mx) {
                mx = nums[i];
                id = i;
            }
        }
        return new TreeNode(mx, helper(nums, l, id - 1), helper(nums, id + 1, r));
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         return helper(nums, 0, nums.size() - 1);
    }
};
