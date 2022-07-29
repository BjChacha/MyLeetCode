// hash table
var twoSum = function(nums, target) {
    const memo = new Map(), n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (memo.has(target - nums[i])) return [memo.get(target - nums[i]), i];
        memo.set(nums[i], i);
    }
    return [];
};