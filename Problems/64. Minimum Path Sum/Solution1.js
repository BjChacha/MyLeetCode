// dp
var minPathSum = function(grid) {
    const m = grid.length, n = grid[0].length;
    let top, left, tmp;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            top = i > 0 ? grid[i-1][j] : Infinity;
            left = j > 0 ? grid[i][j-1] : Infinity;
            tmp = Math.min(top, left);
            grid[i][j] += tmp === Infinity ? 0 : tmp;
        }
    }
    return grid[m-1][n-1];
};