// bfs
var rightSideView = function(root) {
    if (!root) return [];

    let cur = [root];
    let nex = [];
    const res = [];
    while (cur.length) {
        res.push(cur[0].val);
        for (let node of cur) {
            if (node.right) nex.push(node.right);
            if (node.left) nex.push(node.left);
        }
        cur = nex;
        nex = [];
    }
    return res;
};