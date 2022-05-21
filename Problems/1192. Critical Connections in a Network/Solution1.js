// tarjan

var criticalConnections = function(n, connections) {

    function dfs(u, v) {
        pre[v] = cnt++;
        low[v] = pre[v];
        if (adj.hasOwnProperty(v)) {
            for (let w of adj[v]) {
                if (pre[w] === -1) {
                    dfs(v, w);
                    low[v] = Math.min(low[v], low[w]);
                    if (low[w] === pre[w]) res.push([[v, w]]);
                } else if (w !== u) {
                    low[v] = Math.min(low[v], pre[w]);
                }
            }
        }
    }

    const adj = {};
    for (let c of connections) {
        if (!adj.hasOwnProperty(c[0])) adj[c[0]] = [];
        if (!adj.hasOwnProperty(c[1])) adj[c[1]] = [];
        adj[c[0]].push(c[1])
        adj[c[1]].push(c[0])
    }

    let pre = new Array(n).fill(-1);
    let low = new Array(n).fill(-1);
    let cnt = 0;
    const res = [];
    for (let v = 0; v < n; ++v) {
        if (pre[v] === -1) dfs(v, v);
    }
    return res;
}