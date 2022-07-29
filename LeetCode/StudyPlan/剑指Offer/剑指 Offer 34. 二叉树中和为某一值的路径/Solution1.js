// dfs
var pathSum = function(root, target) {
    if (!root) return [];
    const res = [];
    let q = [];
    const dfs = function(node, target) {
        q.push(node.val);
        if (!node.left && !node.right && target == node.val) res.push(q.slice());
        node.left && dfs(node.left, target - node.val);
        node.right && dfs(node.right, target - node.val);
        q.pop();
    }
    dfs(root, target);
    return res;
};