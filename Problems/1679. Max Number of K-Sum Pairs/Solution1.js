// two pointers
var maxOperations = function(nums, k) {
    nums.sort((a, b) => a - b);
    let left = 0, right = nums.length - 1, res = 0, sm;
    while (left < right) {
        sm = nums[left] + nums[right];
        if (sm > k) --right;
        else if (sm < k) ++left;
        else {
            ++res;
            ++left;
            --right;
        }
    }
    return res;
};