// pre-order(right->root->left)
var convertBST = function(root) {
    
    const helper = function(node, sum) {
        if (!node) return sum;
        sum = helper(node.right, sum);
        node.val += sum;
        return helper(node.left, node.val);
    }
    
    helper(root, 0);
    return root;
};