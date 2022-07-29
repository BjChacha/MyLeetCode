// dp
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    const dp = new Map();
    let res = 0, tmp = 0, j;
    for (let i = 0; i < n; ++i) {
        j = dp.has(s[i]) ? dp.get(s[i]) : -1;
        tmp = i - j > tmp ? tmp + 1 : i - j;
        res = Math.max(res, tmp);
        dp.set(s[i], i);
    }
    return res;
};