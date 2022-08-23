// dfs
var exist = function(board, word) {

    const dfs = (i, j, k) => {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] !== word[k]) return false;
        if (k ===  word.length - 1) return true;
        visited[i][j] = true;
        const ans = dfs(i - 1, j, k + 1) || dfs(i + 1, j, k + 1) || dfs(i, j - 1, k + 1) || dfs(i, j + 1, k + 1);
        visited[i][j] = false;
        return ans;
    };
    
    const m = board.length, n = board[0].length;
    const visited = new Array(m).fill(null).map(() => new Array(n).fill(false));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (dfs(i, j, 0)) return true;
        }
    }
    return false;
};
