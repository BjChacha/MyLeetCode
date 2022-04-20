// inorder
var kthSmallest = function(root, k) {
    
    const inorder = function(node) {
        if (!node || k <= 0) return ;
        inorder(node.left);
        if (--k === 0) {
            res = node.val; 
            return;
        }
        inorder(node.right);
    }
    
    let res;
    inorder(root);
    return res;
};