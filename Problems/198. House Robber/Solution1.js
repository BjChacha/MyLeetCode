// dp
var rob = function(nums) {
    const n = nums.length;
    if (n < 2) return Math.max(...nums);
    let first = nums[0], second = Math.max(nums[0], nums[1]);
    for (let i = 2; i < n; ++i) [first, second] = [second, Math.max(first + nums[i], second)];
    return second;
};