// two pointers
var threeSum = function(nums) {
    const n = nums.length, res = [];
    let left, right, sm;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < n - 2; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] === nums[i-1]) continue;
        left = i + 1, right = n - 1;
        while (left < right) {
            sm = nums[i] + nums[left] + nums[right];
            if (sm < 0) {
                ++left;
                while (left < right && nums[left] === nums[left-1]) ++left;
            }
            else if (sm > 0) {
                --right;
                while (left < right && nums[right] === nums[right+1]) --right;
            }
            else {
                res.push([nums[i], nums[left++], nums[right--]]);
                while (left < right && nums[left] === nums[left-1]) ++left;
                while (left < right && nums[right] === nums[right+1]) --right;
            }
        }
    }
    return res;
};