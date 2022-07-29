// binary search
var findDuplicate = function(nums) {
    let left = 1, right = nums.length - 1, mid, cnt;
    while (left < right) {
        mid = (left + right) >>> 1;
        cnt = 0;
        for (let num of nums) {
            if (num <= mid) ++cnt;
        }
        if (cnt <= mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
};
