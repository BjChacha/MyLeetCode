// hash table counting
var firstUniqChar = function(s) {
    const counter = new Map();
    for (let c of s) counter.set(c, counter.get(c) + 1 || 1);
    res = ' ';
    for (let c of s) {
        if (counter.has(c) && counter.get(c) == 1) return c;
    }
    return res;
};