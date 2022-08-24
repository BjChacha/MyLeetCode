// dp
var largestDivisibleSubset = function(nums) {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    const dp = Array(n).fill(1);
    const bp = Array(n).fill(-1);
    let mx = 1, end = 0;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] % nums[j] === 0) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (mx < dp[i]) {
                        mx = dp[i];
                        end = i;
                    }
                    bp[i] = j;
                }
            }
        }
    }
    const res = [];
    while (end >= 0) {
        res.unshift(nums[end]);
        end = bp[end];
    }
    return res;
};
