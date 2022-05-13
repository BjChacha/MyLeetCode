// dp
var numberOfSets = function(n, k) {
    const MOD = 1000000007;
    const dp = new Array(n).fill(0).map(() => new Array(k+1).fill(0)); 

    for (let i = 1; i < n; ++i) {
        for (let j = 1; j <= i; ++j) {
            if (i === j) dp[i][j] = 1;
            else if (j === 1) dp[i][j] = (i + 1) * i / 2;
            else {
                for (let m = 1; m <= j; ++m) dp[i][j] = (dp[i][j] + m * dp[i-m][j-1]) % MOD;
            } 
        }
    }

    return dp[n-1][k];
};