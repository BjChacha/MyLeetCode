// sorting
var frequencySort = function(nums) {
    const cnt = {};
    for (let num of nums) cnt[num] = (cnt[num] ?? 0) + 1;
    nums.sort((a, b) => {
        if (cnt[a] === cnt[b]) {
            return b - a;
        } else {
            return cnt[a] - cnt[b];;
        }
    });
    return nums;
};
