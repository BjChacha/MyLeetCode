// bfs
var isBalanced = function(root) {
    
    const bfs = function(node) {
        if (!node) return [true, 0];
        
        let [leftBalanced, leftDepth] = bfs(node.left);
        let [rightBalanced, rightDepth] = bfs(node.right);
        
        return [leftBalanced && rightBalanced && Math.abs(leftDepth - rightDepth) <= 1, Math.max(leftDepth, rightDepth) + 1];
    }
    
    return bfs(root)[0];
};