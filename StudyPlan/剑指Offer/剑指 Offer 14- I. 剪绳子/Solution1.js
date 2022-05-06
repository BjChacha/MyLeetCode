// greedy
var cuttingRope = function(n) {
    if (n < 4) return n  - 1;
    
    let res = 1;
    while (n > 0) {
        if (n === 4) return res * 4;
        else {
            res *= Math.min(3, n);
            n -= 3;
        }
    }
    return res;
};