// dfs
var buildTree = function(preorder, inorder) {
    if (preorder.length === 0 || inorder.length === 0) return null;

    let root = new TreeNode(preorder[0]);
    let left = inorder.indexOf(preorder[0]);
    let right = inorder.length - left - 1;

    root.left = buildTree(preorder.slice(1, 1 + left), inorder.slice(0, left));
    root.right = buildTree(preorder.slice(1 + left, 1 + left + right), inorder.slice(left + 1, left + right + 1));

    return root;
};