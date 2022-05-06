// stack
var removeDuplicates = function(s, k) {
    let res = [], cnt;
    for (let c of s) {
        if (res.length === 0 || res[res.length-1][1] !== c) {
            res.push([1, c]);
        } else {
            cnt = res[res.length-1][0]
            if (cnt === k - 1) {
                for (let i = 0; i < k - 1; ++i) res.pop();
            } else {
                res.push([cnt + 1, c]);
            }
        }
    }
    return res.map(e => e[1]).join('');
};