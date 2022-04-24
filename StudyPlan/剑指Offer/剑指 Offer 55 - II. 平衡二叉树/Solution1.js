// dfs
var isBalanced = function(root) {

    const dfs = function(node) {
        if (!node) return 0;

        let leftDepth = dfs(node.left);
        if (leftDepth < 0) return -1;
        let rightDepth = dfs(node.right);
        if (rightDepth < 0) return -1;
        return Math.abs(leftDepth - rightDepth) <= 1 ? Math.max(leftDepth, rightDepth) + 1 : -1;
    }

    return dfs(root) === -1 ? false : true;
};