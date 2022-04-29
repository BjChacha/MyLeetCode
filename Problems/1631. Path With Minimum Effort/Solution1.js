// dijkstra
var minimumEffortPath = function(heights) {
    const m = heights.length, n = heights[0].length;
    const dir = [0, 1, 0, -1, 0];
    const dist = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
    dist[0][0] = 0;
    const q = [[0, 0, 0]];
    
    let e, d;
    
    const bisert = function(e) {
        let left = 0, right = q.length - 1, mid;
        while (left <= right) {
            mid = (left + right) >>> 1;
            if (q[mid][2] < e[2]) left = mid + 1;
            else right = mid - 1;
        }
        q.splice(left, 0, e);
    }
    
    while (q.length) {
        e = q.shift();
        if (e[2] > dist[e[0]][e[1]]) continue;
        else if (e[0] === m - 1 && e[1] === n - 1) return e[2];
        else {
            for (let i = 0; i < 4; ++i) {
                let x = e[0] + dir[i], y = e[1] + dir[i+1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;

                d = Math.max(e[2], Math.abs(heights[e[0]][e[1]] - heights[x][y]));
                if (dist[x][y] > d) {
                    dist[x][y] = d;
                    bisert([x, y, d]);
                }
            }
        }
    }
};