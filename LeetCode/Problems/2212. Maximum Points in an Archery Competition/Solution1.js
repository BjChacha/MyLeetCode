// backtracking
var maximumBobPoints = function(numArrows, aliceArrows) {
    const memo = new Map();
    let maxScore = 0;
    let res = null;
    
    const dfs = function(n, k, score, arr) {
        if (n < 0) {
            if (score > maxScore) {
                maxScore = score;
                res = arr;
                if (k > 0) res[0] += k;
            }
        } else {
            dfs(n - 1, k, score, arr.slice());
            if (k > aliceArrows[n]) {
                arr[n] = n == 0 ? k : aliceArrows[n] + 1;
                dfs(n - 1, k - aliceArrows[n] - 1, score + n, arr.slice());
            }
        }
    }
    
    dfs(11, numArrows, 0, new Array(12).fill(0));
    return res;
};