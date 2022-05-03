// dfs
var calcEquation = function(equations, values, queries) {
    const n = equations.length;
    const d = {};
    let a, b;
    for (let i = 0; i < n; ++i) {
        a = equations[i][0], b = equations[i][1];
        if (!d.hasOwnProperty(a)) d[a] = {};
        d[a][b] = values[i];
        if (!d.hasOwnProperty(b)) d[b] = {};
        d[b][a] = 1 / values[i];
    }

    const res = [];
    const visited = {};
    for (let k in d) visited[k] = false;
    
    const dfs = function(a, b) {
        if (a === b) return 1;
        else {
            let ans;
            for (let c in d[a]) {
                if (!visited[c]) {
                    visited[c] = true;
                    ans = d[a][c] * dfs(c, b);
                    visited[c] = false;
                    if (ans > 0) return ans;
                }
            }
            return -1;
        }
    }
    
    for (let q of queries) {
        a = q[0], b = q[1];
        if (!d.hasOwnProperty(a) || !d.hasOwnProperty(b)) res.push(-1);
        else {
            visited[a] = true;
            res.push(dfs(a, b));
            visited[a] = false;
        }
    }
    return res;
};