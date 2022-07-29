// pre-product
var constructArr = function(a) {
    const n = a.length;
    const res = new Array(n).fill(1);
    let pre = 1, suf = 1;
    for (let i = 0; i < n; ++i) {
        res[i] *= pre;
        res[n-i-1] *= suf;
        pre *= a[i];
        suf *= a[n-i-1];
    }
    return res;
};