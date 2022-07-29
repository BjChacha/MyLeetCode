// sort, simulate
var isStraight = function(nums) {
    let zeros = 0, pre;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < 5; ++i) {
        if (nums[i] === 0) ++zeros;
        else {
            if (pre){
                if (nums[i] === pre) return false;
                zeros -= (nums[i] - pre - 1);
                if (zeros < 0) return false;
            }
            pre = nums[i];
        }
    }
    return true;
};