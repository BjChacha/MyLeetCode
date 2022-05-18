// slide window
var lengthOfLongestSubstring = function(s) {
    const memo = new Set();
    let left = 0, right = 0, res = 0;
    while (right < s.length) {
        if (memo.has(s[right])) {
            while (true) {
                memo.delete(s[left]);
                if (s[left++] === s[right]) break;
            }
        }
        res = Math.max(res, right - left + 1);
        memo.add(s[right++]);
    }
    return res;
};