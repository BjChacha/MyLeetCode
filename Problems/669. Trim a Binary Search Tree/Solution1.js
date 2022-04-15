// dfs
var trimBST = function(root, low, high) {
    if (!root) return root;
    if (root.val > high) {
        return trimBST(root.left, low, high);
    } else if (root.val < low) {
        return trimBST(root.right, low, high);
    } else {
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
        return root;
    }
};