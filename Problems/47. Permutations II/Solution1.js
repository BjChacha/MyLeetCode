// perm
var permuteUnique = function(nums) {
    
    const swap = function(i, j) {
        let tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    const reverse = function(i, j) {
        while (i < j) swap(i++, j--);
    } 
    
    const getNext = function() {
        let i = nums.length - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i;
        if (i < 0) return false;
        
        let j = nums.length - 1;
        while (nums[j] <= nums[i]) --j;
        swap(i, j);
        reverse(i + 1, nums.length - 1);
        
        return true;
    }
    
    nums.sort((a, b) => a - b);

    const res = [nums.slice()];
    while (getNext()) res.push(nums.slice());

    return res;
};