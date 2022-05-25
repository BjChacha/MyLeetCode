// dp
var coinChange = function(coins, amount) {
    const dp = new Array(amount + 1).fill(Infinity);
    dp[0] = 0;
    for (let c of coins) {
        for (let i = c; i <= amount; ++i) {
            dp[i] = Math.min(dp[i], dp[i-c] + 1);
        }
    }
    return dp[amount] == Infinity ? -1 : dp[amount];
};