// binary search
var specialArray = function(nums) {

    const bifind = function(target) {
        let lo = 0, hi = n - 1, mi;
        while (lo < hi) {
            mi = (lo + hi + 1) >> 1;
            if (nums[mi] >= target) hi = mi - 1;
            else lo = mi;
        }
        if (nums[lo] >= target) lo --;
        return lo;
    }

    nums.sort((a, b) => a - b);
    const n = nums.length;
    let lo = 0, hi = 1000, mi, cnt;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        cnt = n - bifind(mi) - 1;
        if (mi === cnt) return mi;
        else if (mi > cnt) hi = mi - 1;
        else lo = mi + 1;
    }
    return -1;
};
