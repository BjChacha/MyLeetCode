// Merge Sort (out-place)
var sortArray = function(nums) {
    
    const merge = function(left, mid, right) {
        let i = left, j = mid + 1;
        let sortedArray = [];
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                sortedArray.push(nums[i++]);
            } else {
                sortedArray.push(nums[j++]);
            }
        }
        while (i <= mid) sortedArray.push(nums[i++]);
        while (j <= right) sortedArray.push(nums[j++]);
        
        nums.splice(left, (right - left + 1), ...sortedArray);
    }
    
    const mergeSort = function(left, right) {
        if (left >= right) return;
        
        let mid = left + right >> 1;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
    
    mergeSort(0, nums.length - 1);
    return nums;
};