// one pass
var nextPermutation = function(nums) {
    
    const swap = function(i, j) {
        let tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    const reverse = function(i, j) {
        while (i < j) swap(i++, j--);
    }
    
    const n = nums.length;
    let i = n - 2;
    while (i >= 0 && nums[i] >= nums[i+1]) --i;
    let j;
    if (i >= 0) {
        let j = n - 1;
        while (nums[j] <= nums[i]) --j;
        swap(i, j);
    }
    reverse(i + 1, n - 1);
};