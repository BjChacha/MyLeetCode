// two pointer
var countSubstrings = function(s) {
    const n = s.length;
    let res = 0;
    let l, r;
    for (let i = 0; i < n; ++i) {
        l = r = i;
        while (r + 1 < n && s[r+1] === s[r]) {
            ++res;
            ++r;
        }
        while (l >= 0 && r < n && s[l] === s[r]) {
            ++res;
            --l;
            ++r;
        }
    }
    return res;
};