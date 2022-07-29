// stack + simulate
var lengthLongestPath = function(input) {
    let items = input.split('\n');
    let res = 0, cur = 0, q = [];
    
    const getLevel = function(s) {
        let cnt = 0, i = 0;
        while (i < s.length && s[i] === '\t') ++cnt, ++i;
        let isFile = s.indexOf('.') > 0 ? true : false;
        return [cnt, s.length - i, isFile];
    }
    
    for (let item of items) {
        let [lvl, len, isFile] = getLevel(item);
        if (q.length === 0) {
            q.push(len);
            cur = len;
        } else {
            if (lvl == q.length - 1) {
                cur = cur - q[q.length-1] + len;
                q[q.length-1] = len;
            } else if (lvl > q.length - 1) {
                q.push(len);
                cur += len;
            } else {
                while (q.length - 1 > lvl) {
                    cur -= q.pop();
                }
                cur = cur - q[q.length-1] + len;
                q[q.length-1] = len;
            }
        }
        if (isFile) res = Math.max(res, cur + q.length - 1);
    }
    return res;
};