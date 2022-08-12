// binary search
var searchInsert = function(nums, target) {
    let lo = 0, hi = nums.length, mi;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (nums[mi] < target) lo = mi + 1;
        else hi = mi - 1;
    }
    return lo;
};
