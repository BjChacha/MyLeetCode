// bfs
var shortestPathBinaryMatrix = function(grid) {
    const n = grid.length;
    if (grid[0][0] || grid[n-1][n-1]) return -1;
    
    const dirs = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]];
    let cur = [[0,0,1]];
    for (let item of cur) {
        if (item[0] === n - 1 && item[1] === n - 1) return item[2];
        for (let dir of dirs) {
            let xx = item[0] + dir[0];
            let yy = item[1] + dir[1];
            if (0 <= xx && xx < n && 0 <= yy && yy < n && grid[xx][yy] === 0) {
                cur.push([xx, yy, item[2] + 1]);
                grid[xx][yy] = 1;
            }
        }
    }
    return -1;
    
};
