// dfs
var construct = function(grid) {

    const dfs = function(left, right, top, bottom) {
        if (left === right - 1) return new Node(Boolean(grid[top][left]), true, null, null, null, null);
        let vMid = (left + right) >>> 1; 
        let hMid = (top + bottom) >>> 1;
        let n1 = dfs(left, vMid, top, hMid);
        let n2 = dfs(vMid, right, top, hMid);
        let n3 = dfs(left, vMid, hMid, bottom);
        let n4 = dfs(vMid, right, hMid, bottom);

        if (n1.isLeaf && n2.isLeaf && n3.isLeaf && n4.isLeaf && n1.val === n2.val && n2.val === n3.val && n3.val === n4.val) return new Node(n1.val, true, null, null, null, null);
        else return new Node(false, false, n1, n2, n3, n4);
    }
    
    const n = grid.length;   
    return dfs(0, n, 0, n);
};