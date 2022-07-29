// math
var majorityElement = function(nums) {
    let res, cnt = 0;
    for (let num of nums) {
        if (cnt === 0) {
            res = num;
            ++cnt;
        } else {
            res === num ? ++cnt : --cnt;
        }
    }
    return res;
};