// bit operator, in-place
var gameOfLife = function(board) {
    const m = board.length, n = board[0].length;
    const dx = [0, 0, -1, -1, -1, 1, 1, 1];
    const dy = [-1, 1, -1, 0, 1, -1, 0, 1];
    const countNeibor = function(x, y) {
        let cnt = 0;
        for (let i = 0; i < 8; ++i) {
            let x1 = x + dx[i], y1 = y + dy[i];
            if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
            cnt += board[x1][y1] & 1;
        }
        return cnt;
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let cnt = countNeibor(i, j);
            if (cnt === 3 || cnt == 2 && board[i][j] & 1) board[i][j] |= 2;
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            board[i][j] >>= 1;
        }
    }
};