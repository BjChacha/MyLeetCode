// binary search
var search = function(nums, target) {
    let left = 0, right = nums.length - 1, mid;
    while (left <= right) {
        mid = left + right >>> 1;
        if (nums[mid] === target) return mid;
        else if (nums[mid] > nums[right]) {
            if (nums[left] <= target && nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        else {
            if (nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
        };
    }
    return -1;
};