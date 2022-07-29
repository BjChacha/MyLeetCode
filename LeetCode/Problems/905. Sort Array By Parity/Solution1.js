// two pointers
var sortArrayByParity = function(nums) {
    
    const swap = function(i, j) {
        let tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    const n = nums.length;
    let p1 = 0, p2 = 0;
    while (p1 < n) {
        while (p1 < n && nums[p1] % 2) ++p1;
        if (p1 < n) swap(p1++, p2++);
    }
    return nums;
};