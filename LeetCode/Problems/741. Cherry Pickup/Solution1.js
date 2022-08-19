// memorization
var cherryPickup = function(grid) {
    
    const cache = new Map();
    const dfs = (x1, y1, x2, y2) => {
        if (x1 === n || y1 === n || x2 === n || y2 === n || grid[x1][y1] === -1 || grid[x2][y2] === -1 ) return -Infinity;
    
        const key = `${x1}-${y1}-${x2}-${y2}`;
        if (!cache.has(key)) {
            if (x1 === x2) {
                if (x1 === n - 1 && y1 === n - 1) cache.set(key, grid[x1][y1]);
                else {
                    cache.set(key, grid[x1][y1] + Math.max(
                        dfs(x1 + 1, y1, x2 + 1, y2), 
                        dfs(x1 + 1, y1, x2, y2 + 1), 
                        dfs(x1, y1 + 1, x2, y2 + 1)));
                }
            } else {
                cache.set(key, grid[x1][y1] + grid[x2][y2] + Math.max(
                    dfs(x1 + 1, y1, x2 + 1, y2), 
                    dfs(x1 + 1, y1, x2, y2 + 1), 
                    dfs(x1, y1 + 1, x2 + 1, y2),
                    dfs(x1, y1 + 1, x2, y2 + 1)))
            }
        }
        return cache.get(key);
    }
    
    const n = grid.length;
    const res = dfs(0, 0, 0, 0);
    return res === -Infinity ? 0 : res;
};
