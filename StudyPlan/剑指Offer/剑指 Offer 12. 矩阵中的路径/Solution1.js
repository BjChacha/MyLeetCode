// backtracking (dfs)
var exist = function(board, word) {
    const n = word.length;
    const x = board.length; y = board[0].length;
    const seen = Array(x).fill(false).map(() => Array(y).fill(false));

    const dfs = function(i, j, k) {
        if (k === n) return true;
        for (let [ii, jj] of [[i + 1, j], [i - 1, j], [i, j - 1], [i, j + 1]]) {
            if (ii >= 0 && ii < x && jj >= 0 && jj < y && !seen[ii][jj] && board[ii][jj] === word[k]) {
                seen[ii][jj] = true;
                if (dfs(ii, jj, k + 1)) return true;
                seen[ii][jj] = false;
            }
        }
        return false;
    }

    for (let i = 0; i < x; ++i) {
        for (let j = 0; j < y; ++j) {
            if (board[i][j] === word[0]) {
                seen[i][j] = true;
                if (dfs(i, j, 1)) return true;
                seen[i][j] = false;
            }
        }
    }
    return false;
};