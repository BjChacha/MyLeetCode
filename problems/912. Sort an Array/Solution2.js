// Merge Sort (in-place)
var sortArray = function(nums) {

    const merge = function(left, mid, right) {
        let i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                ++i;
            } else {
                let tmp = nums[j];
                for (let k = j; k > i; --k) {
                    nums[k] = nums[k-1];
                }
                nums[i] = tmp;
                i ++;
                j ++;
                mid ++;
            }
        }
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