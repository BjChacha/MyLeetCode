// dp
var findMaxForm = function(strs, m, n) {
    const dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0))

    const getDigitNum = function(s) {
        let nums = [0, 0]
        for (let c of s) c === '0' ? ++nums[0] : ++nums[1]
        return nums
    }
    
    for (let s of strs) {
        let nums = getDigitNum(s)
        for (let i = m; i >= nums[0]; --i) {
            for (let j = n; j >= nums[1]; --j) {
                dp[i][j] = Math.max(dp[i][j], 1 + dp[i-nums[0]][j-nums[1]])
            }
        }
    }
    return dp[m][n]
}