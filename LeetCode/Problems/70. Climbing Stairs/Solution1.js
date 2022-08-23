// dp
var climbStairs = function(n) {
    let first = 1, second = 1;
    while (n -- > 1) {
        [first, second] = [second, first + second];
    }
    return second;
};
