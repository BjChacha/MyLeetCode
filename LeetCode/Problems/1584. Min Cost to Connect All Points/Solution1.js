// Prim
var minCostConnectPoints = function(points) {

    const getDist = (p1, p2) => Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
    
    const n = points.length;
    let res = 0;
    let dist = new Array(n).fill(Infinity);
    for (let i = 1; i < n; ++i) dist[i] = getDist(points[0], points[i]);

    let connected = new Array(n).fill(false);
    connected[0] = true;
    let connectedCnt = 1;
    let target, d;
    while (connectedCnt < n) {
        target = -1, d = Infinity;
        for (let i = 1; i < n; ++i) {
            if (!connected[i]) {
                if (d > dist[i]) {
                    target = i;
                    d = dist[i];
                }
            }
        }
        res += d;
        connected[target] = true;
        ++connectedCnt;
        for (let i = 1; i < n; ++i) {
            if (!connected[i]) {
                d = getDist(points[target], points[i]);
                if (dist[i] > d) {
                    dist[i] = d;
                }
            }
        }
    }

    return res;
}