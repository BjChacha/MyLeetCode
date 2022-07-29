// dfs
var generateParenthesis = function(n) {
    const dfs = function(n, k, s) {
        if (n === 0 && k === 0) {
            res.push(s);
        } else {
            if (n > 0) dfs(n - 1, k + 1, s + "(");
            if (k > 0) dfs(n, k - 1, s + ")");
        }
    }
    const res = [];
    dfs(n, 0, "");
    return res;
};