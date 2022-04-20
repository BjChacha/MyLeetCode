// stack
var BSTIterator = function(root) {
    this.stack = [root];
    while (this.stack[this.stack.length-1].left) this.stack.push(this.stack[this.stack.length-1].left);
};

BSTIterator.prototype.next = function() {
    let node = this.stack.pop();
    if (node.right) {
        this.stack.push(node.right);
        while (this.stack[this.stack.length-1].left) this.stack.push(this.stack[this.stack.length-1].left);
    }
    return node.val;
};

BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};