// simulate
var backspaceCompare = function(s, t) {
    let s1 = [], s2 = [];
    for (let c of s) {
        if (c === '#') s1.pop();
        else s1.push(c);
    }
    for (let c of t) {
        if (c === '#') s2.pop();
        else s2.push(c);
    }
    if (s1.length !== s2.length) return false;
    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
};