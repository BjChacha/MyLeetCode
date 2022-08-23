// two pointers
var threeSum = function(nums) {
    const n = nums.length, res = [];
    let l, r, sm;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 2 && nums[i] <= 0; ++i) {
        if (i > 0 && nums[i] === nums[i-1]) continue;
        l = i + 1, r = n - 1;
        while (l < r) {
            sm = nums[i] + nums[l] + nums[r];
            if (sm < 0) {
                do {++l;}
                while (l < r && nums[l] === nums[l-1]);
            } else if (sm > 0) {
                do {--r;}
                while (l < r && nums[r] === nums[r+1]);
            } else {
                res.push([nums[i], nums[l], nums[r]]);
                do {++l;}
                while (l < r && nums[l] === nums[l-1]);
                do {--r;}
                while (l < r && nums[r] === nums[r+1]);
            }
        }
    }
    return res;
};
