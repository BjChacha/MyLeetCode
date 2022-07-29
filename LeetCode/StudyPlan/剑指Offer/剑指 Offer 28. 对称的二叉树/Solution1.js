var isSymmetric = function(root) {
    const compare = (a, b) => a && b ? a.val == b.val && compare(a.left, b.right) && compare(a.right, b.left) : a == b;
    return root ? compare(root.left, root.right) : true;
};