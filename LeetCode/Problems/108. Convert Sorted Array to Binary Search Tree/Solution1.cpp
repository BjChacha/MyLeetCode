// pre-order
class Solution {
private:
    TreeNode* preorder(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mi = (lo + hi + 1) >> 1;
        return new TreeNode(nums[mi], solver(nums, lo, mi - 1), solver(nums, mi + 1, hi));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solver(nums, 0, nums.size() - 1);
    }
};
