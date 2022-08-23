// recursion
var countAndSay = function(n) {
    let res = '1';
    let cnt, i, tmp;
    while (--n) {
        cnt = 0, i = 0, tmp = '';
        while (i < res.length) {
            while (cnt === 0 || i < res.length && res[i] === res[i-1]) {
                cnt ++;
                i ++;
            }
            tmp += (cnt + res[i-1]);
            cnt = 0;
        }
        res = tmp;
    }
    return res;
};
