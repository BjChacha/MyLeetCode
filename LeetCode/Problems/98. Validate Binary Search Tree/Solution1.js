const check = (node, mn, mx) => {
    return (
        !node || (
            mn < node.val && node.val < mx &&
            check(node.left, mn, node.val) &&
            check(node.right, node.val, mx)
        )
    );
};

var isValidBST = function(root) {
    return check(root, -Infinity, Infinity);
};
