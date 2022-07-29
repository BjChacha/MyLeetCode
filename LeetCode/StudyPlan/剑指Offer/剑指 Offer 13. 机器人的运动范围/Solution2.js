// dfs
var movingCount = function(m, n, k) {
    const getSum = function(a, b) {
        let res = 0;
        while (a) res += a % 10, a = Math.floor(a / 10);
        while (b) res += b % 10, b = Math.floor(b / 10);
        return res;
    }

    const dfs = function(i, j) {
        if (i < m && j < n && !seen[i][j] && getSum(i, j) <= k) {
            seen[i][j] = true;
            return 1 + dfs(i + 1, j) + dfs(i, j + 1)
        };
        return 0;
    }
    
    const seen = Array(m).fill(false).map(() => Array(n).fill(false));
    return dfs(0, 0);
}