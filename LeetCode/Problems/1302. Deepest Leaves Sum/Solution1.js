// bfs
var deepestLeavesSum = function(root) {
    if (!root) return 0;
    let cur = [root];
    let nex;
    let res;
    while(cur.length) {
        res = 0
        nex = [];
        for (let node of cur) {
            res += node.val;
            if (node.left) nex.push(node.left);
            if (node.right) nex.push(node.right);
        }
        cur = nex;
    }
    return res;
};