// binary search
var lengthOfLIS = function(nums) {
    
    const find = function(target) {
        let left = 0, right = q.length - 1
        while (left < right) {
            let mid = (left + right) >>> 1;
            if (q[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    const q = [];
    for (let num of nums) {
        if (q.length === 0 || q[q.length-1] < num) q.push(num);
        else q[find(num)] = num;
    }
    return q.length;
};