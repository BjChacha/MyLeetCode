// dp
var coinChange = function(coins, amount) {
    coins.sort((a, b) => a - b);
    const dp = new Array(amount + 1).fill(Infinity);
    dp[0] = 0;
    for (let i = 1; i <= amount; ++i) {
        for (let c of coins) {
            if (c > i) break;
            dp[i] = Math.min(dp[i], dp[i-c] + 1);
        }
    }
    return dp[amount] === Infinity ? -1 : dp[amount];
};