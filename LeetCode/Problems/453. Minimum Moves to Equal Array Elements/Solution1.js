// math
var minMoves = function(nums) {
    return nums.reduce((a, b) => a + b) - nums.length * Math.min(...nums);
};