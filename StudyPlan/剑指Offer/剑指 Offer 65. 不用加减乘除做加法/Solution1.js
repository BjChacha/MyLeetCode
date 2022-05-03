// bit manipulation
var add = function(a, b) {
    let c;
    while (b) {
        c = (a & b) << 1;
        a ^= b;
        b = c;
    }
    return a;
};