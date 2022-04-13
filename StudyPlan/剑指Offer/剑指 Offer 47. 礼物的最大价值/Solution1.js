// dp
var maxValue = function(grid) {
    const n = grid.length, m = grid[0].length;

    const dp = new Array(n).fill(0).map(()=>new Array(m).fill(0));
    let top, left;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            top = i > 0 ? dp[i-1][j] : 0;
            left = j > 0 ? dp[i][j-1] : 0;
            dp[i][j] = grid[i][j] + Math.max(top, left);
        }
    }
    return dp[n-1][m-1];
};