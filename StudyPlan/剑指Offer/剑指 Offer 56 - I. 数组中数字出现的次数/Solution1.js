// bit manipulation
var singleNumbers = function(nums) {
    let x = 0;
    for (let num of nums) x ^= num;

    let flag = x & (-x);
    let res = 0;
    for (let num of nums) {
        if (num & flag) res ^= num;
    }
    return [res, res ^ x];
};