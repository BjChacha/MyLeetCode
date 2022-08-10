// preorder
const preorder = (nums, lo, hi) => {
    if (lo > hi) return null;
    const mi = (lo + hi + 1) >> 1;
    return new TreeNode(nums[mi], preorder(nums, lo, mi - 1), preorder(nums, mi + 1, hi));
};

var sortedArrayToBST = function(nums) {
    return preorder(nums, 0, nums.length - 1);
};
