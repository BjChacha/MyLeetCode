// inorder
var treeToDoublyList = function(root) {
    if (!root) return root;
    let res = null;
    let preNode = null;
    const inorder = function(node) {
        if (node) {
            inorder(node.left);
            if (!res) res = node;
            if (preNode) {
                preNode.right = node;
                node.left = preNode;
            } 
            preNode = node;
            inorder(node.right);
        }
    }
    inorder(root);
    preNode.right = res;
    res.left = preNode;
    return res;
};