// greedy
var reconstructQueue = function(people) {
    const res = [];
    people.sort((a, b) => {
        if (a[1] === b[1]) {
            return a[0] - b[0];
        } else {
            return a[1] - b[1];
        }
    });
    // console.log(people);
    for (let p of people) {
        if (res.length === 0) res.push(p);
        else {
            let i = 0, cnt = p[1];
            while (i < res.length && res[i][0] < p[0]) ++i;
            while (i < res.length && cnt) {
                if (res[i][0] >= p[0]){ 
                    --cnt;
                }
                ++i;
            }
            while (i < res.length && res[i][0] < p[0]) ++i;
            res.splice(i, 0, p);
        }
    }
    return res;
};