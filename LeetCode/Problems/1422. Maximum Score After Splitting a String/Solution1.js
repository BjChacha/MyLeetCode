var maxScore = function(s) {
    let tmp = +(s[0] === '0');
    for (let i = 1; i < s.length; ++i) tmp += (s[i] === '1');
    let res = tmp;
    for (let i = 1; i < s.length - 1; ++i) {
        if (s[i] === '0') tmp ++;
        else tmp --;
        res = Math.max(res, tmp);
    }
    return res;
};
