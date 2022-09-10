// mono queue
var maxSlidingWindow = function(nums, k) {
    const n = nums.length;
    const q = [], res = [];
    for (let i = 0; i < k; ++i) {
        while (q.length > 0 && nums[q.at(-1)] <= nums[i]) q.pop();
        q.push(i);
    }
    res.push(nums[q[0]]);
    for (let i = k; i < n; ++i) {
        while (q.length > 0 && nums[q.at(-1)] <= nums[i]) q.pop();
        q.push(i);
        while (q[0] <= i - k) q.shift();
        res.push(nums[q[0]]);
    }
    return res;
};
