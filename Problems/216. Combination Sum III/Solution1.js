// rescursion
var combinationSum3 = function(k, n) {
    
    const res = [];    
    const dfs = (i, sm, ls) => {
        if (ls.length > k) return;
        else if (ls.length === k) {
            if (sm === n) res.push(ls.slice());
        } else {
            for (let j = i + 1; j < 10; ++j) {
                ls.push(j);
                dfs(j, sm + j, ls);
                ls.pop();
            }
        }
    };
    for (let i = 1; i <= 10 - k; ++i) dfs(i, i, [i]);
    return res;
};