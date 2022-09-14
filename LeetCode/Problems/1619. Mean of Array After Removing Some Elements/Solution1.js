// sorting
var trimMean = function(arr) {
    const n = arr.length;
    arr.sort((a, b) => a - b);
    const begin = Math.floor(n / 20), end = n - begin;
    let sum = 0;
    for (let i = begin; i < end; ++i) sum += arr[i];
    return sum / (n * 0.9);
};
