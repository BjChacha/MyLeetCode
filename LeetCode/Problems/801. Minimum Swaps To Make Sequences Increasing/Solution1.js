// dp
var minSwap = function(nums1, nums2) {
    const n = nums1.length;
    const dp = [Array(n), Array(n)];
    for (let arr of dp) {
        arr.fill(Infinity);
    }
    dp[0][0] = 0;
    dp[1][0] = 1;
    for (let i = 1; i < n; ++i) {
        if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
            // 不交换
            dp[0][i] = Math.min(dp[0][i], dp[0][i-1]);
            dp[1][i] = Math.min(dp[1][i], dp[1][i-1] + 1);
        }
        if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
            // 可交换
            dp[0][i] = Math.min(dp[0][i], dp[1][i-1]);
            dp[1][i] = Math.min(dp[1][i], dp[0][i-1] + 1);
        }
    }
    return Math.min(dp[0][n-1], dp[1][n-1]);
};
