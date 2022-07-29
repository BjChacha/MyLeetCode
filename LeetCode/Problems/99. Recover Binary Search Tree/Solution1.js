// inorder
var recoverTree = function(root) {
    let first = null, second = null;
    
    const inorder = function(node) {
        if (node) {
            inorder(node.left);
            
            if (!first || !second && first.val < node.val) first = node;
            else if (!second || second.val > node.val) second = node;
            
            inorder(node.right);
        }
    }
    
    inorder(root);
    [first.val, second.val] = [second.val, first.val];
    return;
};