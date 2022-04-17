// pre-order(right->root->left), using global variable (accu)
var convertBST = function(root) {
    if (!root) return root;
    
    let accu = 0
    const helper = function(node) {
        node.right && helper(node.right);
        accu += node.val;
        node.val = accu;
        node.left && helper(node.left);
    }
    
    helper(root);
    return root;
};