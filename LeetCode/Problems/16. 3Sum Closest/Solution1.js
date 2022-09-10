// two pointers
var threeSumClosest = function(nums, target) {
    const n = nums.length;
    let res, l, r, sm;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] === nums[i-1]) continue;
        l = i + 1, r = n - 1;
        while (l < r) {
            sm = nums[i] + nums[l] + nums[r];
            if (!res || Math.abs(sm - target) < Math.abs(res - target)) res = sm;
            if (sm > target) {
                do {--r;} while (l < r && nums[r] === nums[r+1]);
            } else if (sm < target) {
                do {++l;} while (l < r && nums[l] === nums[l-1]);
            } else {
                return target;
            }
        }
    }
    return res;
};
