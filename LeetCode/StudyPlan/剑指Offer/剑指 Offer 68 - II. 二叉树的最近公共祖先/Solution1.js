// dfs
var lowestCommonAncestor = function(root, p, q) {
    if (!root || root.val === p.val || root.val === q.val) return root;
    let left = lowestCommonAncestor(root.left, p, q);
    let right = lowestCommonAncestor(root.right, p, q);
    if (!left && !right) return null;
    if (!left) return right;
    if (!right) return left;
    return root;
};