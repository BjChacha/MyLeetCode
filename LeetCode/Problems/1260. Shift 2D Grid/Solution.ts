function shiftGrid(grid: number[][], k: number): number[][] {
    const m = grid.length, n = grid[0].length;
    k %= (m * n);
    for (let i = 0; i < Math.floor(k / n); ++i) {
        grid.splice(0, 0, grid.pop());
    }
    if (k % n) {
        let tmp: number[];
        for (let line of grid) {
            if (tmp) line.splice(0, 0, ...tmp);
            tmp = line.splice(line.length - k % n);
        }
        grid[0].splice(0, 0, ...tmp);
    }
    return grid;
};