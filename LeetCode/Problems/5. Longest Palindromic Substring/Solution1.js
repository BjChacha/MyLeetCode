// two pointers
var longestPalindrome = function(s) {
    const n = s.length;
    let l, r, resStart = 0, resEnd = 0, i = 0;
    while (i < n - Math.floor((resStart - resEnd + 1) / 2)) {
        l = r = i;
        // skip the duplicated char
        while (r < n - 1 && s[r] == s[r+1]) ++r;
        i = r + 1;
        while (l > 0 && r < n -1 && s[r+1] == s[l-1]) {
            --l;
            ++r;
        }
        if (r - l > resEnd - resStart) {
            [resStart, resEnd] = [l, r];
        }
    }
    return s.substring(resStart, resEnd + 1);
};