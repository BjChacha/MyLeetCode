// Quici Sort (two-pointers)
var sortArray = function(nums) {
    const quickSort = function(left, right) {
        if (left >= right) return;
        
        // let pivot = left;
        let pivot = Math.floor(Math.random() * (right - left + 1)) + left;
        // let pivot = left + right >> 1;
        [nums[left], nums[pivot]] = [nums[pivot], nums[left]];
        
        let l = left, r = right + 1;
        while (l < r) {
            do {++l;} while (l <= right && nums[l] < nums[left]);
            do {--r;} while (nums[r] > nums[left]);
            if (l >= r) break;
            [nums[l], nums[r]] = [nums[r], nums[l]];
        }
        [nums[r], nums[left]] = [nums[left], nums[r]];
        
        quickSort(left, r - 1);
        quickSort(r + 1, right);
    }
    quickSort(0, nums.length - 1);
    return nums;
};