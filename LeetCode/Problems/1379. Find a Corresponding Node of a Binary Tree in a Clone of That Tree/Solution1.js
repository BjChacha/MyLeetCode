// inorder
var getTargetCopy = function(original, cloned, target) {
    let cur = cloned;
    function preorder(node) {
        if (!node || node.val === target.val) return node;
        else return preorder(node.left) || preorder(node.right);
    }
    return preorder(cloned);
};