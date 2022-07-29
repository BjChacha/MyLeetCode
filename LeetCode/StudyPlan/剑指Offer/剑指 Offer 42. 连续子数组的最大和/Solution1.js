// dp
var maxSubArray = function(nums) {
    let res = -Infinity, sm = 0;
    nums.forEach((x) => {
        sm = Math.max(sm + x, x);
        res = Math.max(res, sm);
    })
    return res;
};