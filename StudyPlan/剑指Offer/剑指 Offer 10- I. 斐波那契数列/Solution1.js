var fib = function(n) {
    const arr = [0, 1];
    while (n > 1) {
        [arr[0], arr[1]] = [arr[1], (arr[0] + arr[1]) % 1000000007];
        --n; 
    }
    return arr[n];
};