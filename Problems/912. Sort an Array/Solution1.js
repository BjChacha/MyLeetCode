// quicksort (single-side)
var sortArray = function(nums) {
    
    const partition = function(left, right) {
        if (left >= right) return;
        
        const pivot = Math.floor(Math.random() * (right - left + 1) + left);
        swap(left, pivot);
        
        let mid = left;
        for (let i = left + 1; i <= right; ++i) {
            if (nums[i] < nums[left]) {
                swap(i, ++mid);
            }
        }
        swap(left, mid);
        
        partition(left, mid - 1);
        partition(mid + 1, right);
        
    }
    
    const swap = function(i, j) {
        let tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    partition(0, nums.length - 1);
    return nums;
};