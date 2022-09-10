// two pointers
var maxArea = function(height) {
    let res = 0, l = 0, r = height.length - 1;
    while (l < r) {
        res = Math.max(res, Math.min(height[l], height[r]) * (r - l));
        height[l] < height[r] ? ++l : --r;
    }
    return res;
};
