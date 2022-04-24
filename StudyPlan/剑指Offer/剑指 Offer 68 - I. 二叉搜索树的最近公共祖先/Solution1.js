var lowestCommonAncestor = function(root, p, q) {
    
    let node = root;
    while (node) {
        if (node.val > p.val && node.val > q.val) node = node.left;
        else if (node.val < p.val && node.val < q.val) node = node.right;
        else break;
    }

    return node;
};