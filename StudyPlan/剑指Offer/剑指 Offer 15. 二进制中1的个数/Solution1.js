// bit manipulation
var hammingWeight = function(n) {
    let res = 0;
    while (n) {
        res += n & 1;
        n >>>= 1;
    }
    return res;
};