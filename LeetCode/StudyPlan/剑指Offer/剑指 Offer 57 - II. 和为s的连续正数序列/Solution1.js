// two pointers
var findContinuousSequence = function(target) {
    const res = [];
    const end = Math.ceil(target / 2);

    let left = 1, right = 1, sm, tmp;
    while (right <= end) {
        sm = (left + right) * (right - left + 1) / 2;
        
        if (sm < target) ++right;
        else if (sm > target) ++left;
        else {
            tmp = new Array(right - left + 1).fill(0).map((e, i) => left + i);
            res.push(tmp);
            ++left;
        }
    }
    return res;
}