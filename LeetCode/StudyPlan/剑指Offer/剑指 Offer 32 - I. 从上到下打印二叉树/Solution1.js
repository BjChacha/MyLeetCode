// queue
var levelOrder = function(root) {
    const res = [];
    if (!root) return res;
    const q = [root]
    while (q.length > 0) {
        res.push(q[0].val);
        if (q[0].left) q.push(q[0].left);
        if (q[0].right) q.push(q[0].right);
        q.shift();
    }
    return res;
};