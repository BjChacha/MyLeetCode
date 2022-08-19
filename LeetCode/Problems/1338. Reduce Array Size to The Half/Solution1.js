// counter
var minSetSize = function(arr) {
    const counter = {};
    for (const a of arr) counter[a] = (counter[a] ?? 0) + 1;
    const values = Object.values(counter);
    values.sort((a, b) => b - a);
    let res = 0, tmp = 0, n = arr.length;
    for (const a of values) {
        if (tmp >= n / 2) break;
        res += 1;
        tmp += a;
    }
    return res;
};
