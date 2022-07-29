// bfs
var connect = function(root) {
    if (!root) return root;
    
    let cur = [root];
    let nex;
    let pre;
    while (cur.length) {
        nex = [];
        pre = null;
        for (let node of cur) {
            if (pre) pre.next = node;
            pre = node;
            if (node.left) nex.push(node.left);
            if (node.right) nex.push(node.right);
        }
        cur = nex;
        nex = [];
    }
    return root;
};