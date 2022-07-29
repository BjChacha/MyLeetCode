// dfs
var maxPathSum = function(root) {
    let res = -Infinity;

    let dfs = function(node) {
        if (!node) return 0;
        let left = Math.max(0, dfs(node.left));
        let right = Math.max(0, dfs(node.right));
        res = Math.max(res, left + right + node.val)
        return node.val + Math.max(left, right);
    }
    dfs(root);
    return res;
};