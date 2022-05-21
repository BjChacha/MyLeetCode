// dp
var uniquePathsWithObstacles = function(obstacleGrid) {
    const n = obstacleGrid.length, m = obstacleGrid[0].length;
    if (obstacleGrid[0][0] === 1 || obstacleGrid[n-1][m-1] === 1) return 0;
    const paths = new Array(n).fill(-1).map(() => new Array(m).fill(0));
    paths[n-1][m-1] = 1;
    for (let i = n - 2; i >= 0; --i) {
        if (obstacleGrid[i][m-1] === 0) paths[i][m-1] = paths[i+1][m-1];
    }
    for (let i = m - 2; i >= 0; --i) {
        if (obstacleGrid[n-1][i] === 0) paths[n-1][i] = paths[n-1][i+1];
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = m - 2; j >= 0; --j) {
            if (obstacleGrid[i][j] === 0) paths[i][j] = paths[i][j+1] + paths[i+1][j];
        }
    }
    return paths[0][0];
};