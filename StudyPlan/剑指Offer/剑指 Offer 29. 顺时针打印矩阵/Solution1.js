// simulate
var spiralOrder = function(matrix) {
    const n = matrix.length
    if (n === 0) return [];
    const m = matrix[0].length;
    if (m === 0) return [];
    let res = [];
    let top = left = 0, right = m - 1, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for (let i = left; i <= right; ++i) res.push(matrix[top][i]);
        for (let i = ++top; i <= bottom; ++i) res.push(matrix[i][right]);
        if (top <= bottom) {
            for (let i = --right; i >= left; --i) res.push(matrix[bottom][i]);
        }
        if (left <= right) {
            for (let i = --bottom; i >= top; --i) res.push(matrix[i][left]);
        }
        ++left;
    }
    return res;
};