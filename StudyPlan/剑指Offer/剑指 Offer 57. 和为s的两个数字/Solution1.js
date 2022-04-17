// two pointers
var twoSum = function(nums, target) {
    let i = 0, j = nums.length - 1, tmp;
    while (i < j) {
        tmp = nums[i] + nums[j];
        if (tmp === target) return [nums[i], nums[j]];
        else if (tmp > target) --j;
        else ++i;
    }
    return [];
};