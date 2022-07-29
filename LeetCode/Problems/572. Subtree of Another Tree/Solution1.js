// dfs
var isSubtree = function(root, subRoot) {
    
    if (!root) return false;
    let res = dfs(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    return res;
    
};

var dfs = function(a, b) {
    if (!a || !b) return a == b;
    return a.val === b.val && dfs(a.left, b.left) && dfs(a.right, b.right);
}