// slide window
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    const map = new Map();
    let left = 0, right = 0, tmp, res = 0;
    while (right < n) {
        if (map.has(s[right])) {
            tmp = map.get(s[right]);
            while (left <= tmp) map.delete(s[left++]);
        }
        map.set(s[right], right);
        res = Math.max(res, right - left + 1);
        ++right;
    }
    return res;
};