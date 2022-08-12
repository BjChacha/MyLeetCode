// recursion
var lowestCommonAncestor = function(root, p, q) {
    if (!root) return null;
    if (root.val === p.val || root.val === q.val) return root;
    const l = lowestCommonAncestor(root.left, p, q);
    const r = lowestCommonAncestor(root.right, p, q);
    if (l && r) return root;
    else return l ?? r;
};
