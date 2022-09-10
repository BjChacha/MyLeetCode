// dfs
var numIslands = function(grid) {
    const m = grid.length, n = grid[0].length;
    const visited = Array(m).fill(null).map(() => Array(n).fill(false));
    
    const dfs = (i, j) => {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] === '0') return false;
        grid[i][j] = '0'
        visited[i][j] = true;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
        return true;
    }

    let res = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (dfs(i, j)) res ++;
        }
    }
    return res;
};
