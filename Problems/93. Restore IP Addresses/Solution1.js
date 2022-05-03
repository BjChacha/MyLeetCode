// pointers
var restoreIpAddresses = function(s) {
    let res = [];
    const n = s.length;
    if (n < 4) return res;
    let e1 = Math.min(3, n - 3), e2, e3, s3;
    let p1, p2, p3, p4;
    for (let i = 1; i <= e1; ++i) {
        e2 = Math.min(i + 3, n - 2);
        for (let j = i + 1; j <= e2; ++j) {
            e3 = Math.min(j + 3, n - 1);
            for (let k = j + 1; k <= e3; ++k) {
                if (n - k > 3) continue;

                p1 = +s.slice(0, i);
                if (p1 > 255 || (i > 1 && s[0] === '0')) continue;
                p2 = +s.slice(i, j);
                if (p2 > 255 || (j - i > 1 && s[i] === '0')) continue;
                p3 = +s.slice(j, k);
                if (p3 > 255 || (k - j > 1 && s[j] === '0')) continue;
                p4 = +s.slice(k, n);
                if (p4 > 255 || (n - k > 1 && s[k] === '0')) continue;
                
                res.push([p1, p2, p3, p4].join('.'));
            }
        }
    }
    
    return res;
};