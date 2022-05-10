// simulate
var diStringMatch = function(s) {
    let res = [0], top = 0, bot = 0;
    for (let c of s) c === 'I' ? res.push(top++ + 1) : res.push(bot-- - 1);
    return res.map(x => x - bot);
};