var mirrorTree = function(root) {
    if (!root) return root;
    [root.left, root.right] = [mirrorTree(root.right), mirrorTree(root.left)];
    return root
};