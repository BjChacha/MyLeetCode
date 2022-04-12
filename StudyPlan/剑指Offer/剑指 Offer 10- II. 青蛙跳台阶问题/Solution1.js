var numWays = function(n) {
    let num = [1,1];
    while (n > 1) {
        [num[0], num[1]] = [num[1], (num[0] + num[1]) % 1000000007];
        --n;
    }
    return num[n];
};
