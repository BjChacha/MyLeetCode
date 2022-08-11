var reformat = function(s) {
    let na = 0, nd = 0;
    for (let c of s) isNaN(c) ? na ++ : nd ++;
    if (Math.abs(na - nd) > 1) return '';
    let res = new Array(s.length);
    let i = +(na >= nd);
    let j = +(na < nd);
    for (let c of s) {
        if (isNaN(c)) {
            res[j] = c;
            j += 2;
        } else {
            res[i] = c;
            i += 2;
        }
    }
    return res.join('');
};
