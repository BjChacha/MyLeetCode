// simulate
var isCovered = function(ranges, left, right) {
    const res = new Array(right - left + 1).fill(false);
    let start, end;
    for (let [a, b] of ranges) {
        start = Math.max(left, a);
        end = Math.min(right, b);
        if (start > end) continue;
        for (let i = start; i <= end; ++i) res[i-left] = true;
    }
    for (let e of res) {
        if (!e) return false;
    }
    return true;
};