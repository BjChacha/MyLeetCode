// dp
var lengthOfLIS = function(nums) {
    const arr = [];
    let lo, hi, mi;
    for (let num of nums) {
        if (arr.length === 0 || arr.slice(-1) < num) arr.push(num);
        else {
            lo = 0, hi = arr.length - 1;
            while (lo < hi) {
                mi = lo  + hi >> 1;
                if (arr[mi] < num) lo = mi + 1;
                else hi = mi;
            }
            arr[lo] = num;
        }
    }
    return arr.length;
};
