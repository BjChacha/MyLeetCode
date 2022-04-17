// bfs
var zigzagLevelOrder = function(root) {
    if (!root) return [];
    const res = [];
    let cur = [root], nex = [], reversed = false;
    while (cur.length) {
        if (reversed) res.push(cur.map((x)=>x.val).reverse());
        else res.push(cur.map((x)=>x.val));
        
        for (let node of cur) {
            if (node.left) nex.push(node.left);
            if (node.right) nex.push(node.right);
        }

        cur = nex;
        nex = [];
        reversed = !reversed;
    }
    return res;
};