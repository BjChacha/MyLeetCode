// sorting
var findUnsortedSubarray = function(nums) {
    const sorted = [...nums].sort((a, b) => a - b);
    const n = nums.length;
    let res = n;

    for (let i = 0; i < n && nums[i] === sorted[i]; ++i, --res) ;
    if (res > 0) for (let i = n - 1; i >= 0 && nums[i] === sorted[i]; --i, --res) ;
    return res;
};