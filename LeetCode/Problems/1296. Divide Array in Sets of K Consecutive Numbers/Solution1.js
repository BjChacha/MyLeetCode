// hash table
var isPossibleDivide = function(nums, k) {
    const n = nums.length;
    if (n % k) return false;
    
    const counter = {};
    for (const num of nums) counter[num] = (counter[num] ?? 0) + 1;
    nums.sort((a, b) => a - b);
    for (const num of nums) {
        if (counter[num] === 0) continue;
        for (let i = 0; i < k; ++i) {
            if (!counter[num+i] > 0) return false;
            counter[num+i] --;
        }
    }
    return true;
};
