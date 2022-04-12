// slide window
var lengthOfLongestSubstring = function(s) {
    const stored = new Map(), n = s.length;
    let left = 0, right = 0, res = 0, idx;
    while (right < n) {
        if (stored.has(s[right])) {
            idx = stored.get(s[right]);
            while (left <= idx) stored.delete(s[left++]);
        }
        stored.set(s[right], right);
        res = Math.max(res, right - left + 1);
        ++right;
    }  
    return res;
};