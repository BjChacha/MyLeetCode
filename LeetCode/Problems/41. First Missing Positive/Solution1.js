// in-place mark
var firstMissingPositive = function(nums) {
    const n = nums.length;
    let idx;
    for (let i = 0; i < n; ++i) {
        if (nums[i] <= 0) nums[i] = Infinity;
    }
    for (let i = 0; i < n; ++i) {
        if (nums[i] === Infinity) continue;
        idx = Math.abs(nums[i])
        if (nums[idx-1] > 0) nums[idx-1] = - nums[idx-1];
    }
    
    for (let i = 0; i < n; ++i) {
        if (nums[i] >= 0) return i + 1;
    }
    return n + 1;
};