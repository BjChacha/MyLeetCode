// inorder
var kthLargest = function(root, k) {

    const inorder = function(node) {
        let res;
        if (node.right) res = inorder(node.right);
        if (!res && k-- === 1) res = node.val;
        if (!res && node.left) res = inorder(node.left); 
        return res;
    }
    return inorder(root);
};