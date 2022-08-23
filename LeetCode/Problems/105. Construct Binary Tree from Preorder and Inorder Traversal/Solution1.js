// recursion
var buildTree = function(preorder, inorder) {
    
    const helper = (left, right) => {
        if (left > right) return null;
        let i = left;
        const val = preorder[preIdx++];
        while (inorder[i] !== val) ++i;
        return new TreeNode(val, helper(left, i - 1), helper(i + 1, right));
    };

    let preIdx = 0;
    return helper(0, inorder.length - 1)
};
