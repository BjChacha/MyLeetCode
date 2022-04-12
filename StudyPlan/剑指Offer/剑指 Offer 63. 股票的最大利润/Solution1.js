// dp
var maxProfit = function(prices) {
    let sm = 0, res = 0;
    for (let i = 0; i < prices.length - 1; ++i) {
        sm = Math.max(0, sm + prices[i+1] - prices[i]);
        res = Math.max(res, sm);
    }
    return res;
};