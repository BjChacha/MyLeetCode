// BFS
var levelOrder = function(root) {
    const res = []
    if (!root) return res;
    let cur = [root];
    let nex = [];
    while (cur.length > 0) {
        res.push(cur.map((x)=>x.val));
        for (let node of cur) {
            if (node.left) nex.push(node.left);
            if (node.right) nex.push(node.right);
        }
        cur = nex;
        nex = [];
    }
    return res;
};