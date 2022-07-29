// simulation
var numberOfLines = function(widths, s) {
    const codeAt_a = 'a'.charCodeAt();
    let row = 1, curLen = 0, tmp;
    for (const c of s) {
        tmp = widths[c.charCodeAt()-codeAt_a]
        curLen += tmp;
        if (curLen > 100) {
            ++ row;
            curLen = tmp;
        }
    }
    return [row, curLen];
};