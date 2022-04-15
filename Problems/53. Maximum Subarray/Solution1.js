// dp
var maxSubArray = function(nums) {
    let res = -Infinity, sum = 0;
    for (let num of nums) {
        sum = Math.max(num, sum + num);
        res = Math.max(res, sum);
    }
    return res;
};