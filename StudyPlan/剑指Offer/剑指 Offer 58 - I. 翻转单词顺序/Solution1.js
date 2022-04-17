// simulate
var reverseWords = function(s) {
    let arr = [];
    s.trim().split(' ').reverse().forEach((x) => {
        if (x) arr.push(x);
    });
    return arr.join(' ');
};