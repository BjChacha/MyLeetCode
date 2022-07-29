// bellman-ford
var networkDelayTime = function(times, n, k) {
    
    const ad = new Array(n).fill(0).map(() => new Array(n).fill(Infinity));
    for (let t of times) {
        ad[t[0]-1][t[1]-1] = t[2];
    }
    const dist = new Array(n).fill(Infinity);
    dist[k-1] = 0;
    let cur = [k-1];
    let nex = [];
    while (cur.length) {
        for (let node of cur) {
            for (let i = 0; i < n; ++i) {
                if (ad[node][i] !== Infinity) {
                    let new_d = dist[node] + ad[node][i];
                    if (new_d < dist[i]) {
                        dist[i] = new_d;
                        nex.push(i);
                    }
                }
            }
        }
        cur = nex;
        nex = [];
    }
    let res = 0;
    for (let i = 0; i < n; ++i) {
        if (dist[i] === Infinity) return -1;
        res = Math.max(res, dist[i]);
    }
    return res;
};