// slide windows
var maxSlidingWindow = function(nums, k) {
    const n = nums.length;
    if (n === 0) return [];
    let q = [];
    let res = [];

    for (let i = 0; i < k; ++i) {
        while (q.length > 0 && nums[q[q.length-1]] <= nums[i]) q.pop();
        q.push(i);
    }
    res.push(nums[q[0]]);

    for (let i = k; i < n; ++i) {
        while (q.length > 0 && nums[q[q.length-1]] <= nums[i]) q.pop();
        q.push(i);
        while (q[0] <= i - k) q.shift()
        res.push(nums[q[0]]);
    }
    return res;
};