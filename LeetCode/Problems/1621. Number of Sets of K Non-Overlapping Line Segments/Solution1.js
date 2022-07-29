// dfs with memo
var numberOfSets = function(n, k) {
    const MOD = 1000000007;
    const memo = new Array(n+1).fill(-1).map(() => new Array(n+1).fill(-1));
    const dp = function(n, k) {
        if (memo[n][k] < 0) {
            if (n === k) memo[n][k] = 1;
            else if (k === 1) memo[n][k] = n * (n + 1) / 2;
            else{
                memo[n][k] = 0;
                for (let i = 1; i <= n -  k + 1; ++i) {
                    memo[n][k] = (memo[n][k] + i * dp(n - i, k - 1)) % MOD;
                }
            }
        }
        return memo[n][k];
    }
    return dp(n - 1, k);
};