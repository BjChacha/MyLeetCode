// sorting 
var topKFrequent = function(nums, k) {
    const counter = new Map();
    nums.forEach((num) => counter.set(num, counter.get(num) + 1 || 1));
    const arr = [...counter.entries()].sort((a, b) => b[1] - a[1]);
    let res = arr.map(x=>x[0]).slice(0, k);
    return res;
};