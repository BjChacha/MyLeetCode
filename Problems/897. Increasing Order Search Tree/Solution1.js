// iorder
var increasingBST = function(root) {
    
    const inorder = function(node) {
        if (!node) return;
        inorder(node.left); 
        
        let rightTmp = node.right;
        node.left = null;
        node.right = null;
        cur.right = node;
        cur = cur.right;
        
        inorder(rightTmp);
    }
    
    const dummy = new TreeNode(-1);
    let cur = dummy;
    inorder(root);
    return dummy.right;
};