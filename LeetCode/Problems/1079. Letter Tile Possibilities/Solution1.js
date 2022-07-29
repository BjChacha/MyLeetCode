// multiple permutation
var numTilePossibilities = function(tiles) {
    const factorials = [1, 1, 2, 6, 24, 120, 720, 5040];
    const counter = new Map();
    for (let t of tiles) counter.set(t, counter.has(t) ? counter.get(t) + 1 : 1);
    
    const n = counter.size;
    const values = [...counter.values()];

    const cal = function() {
        let tmp = factorials[values.reduce((a,b)=>a+b)];
        if (tmp === 0) return 0;
        for (let v of values) tmp /= factorials[v];
        return tmp;
    }
    
    const dfs = function(i) {
        if (i === n) res += cal();
        else {
            let bak = values[i];
            while (values[i] >= 0) {
                dfs(i + 1);
                --values[i];
            }
            values[i] = bak;
        }
    }
    let res = 0;
    dfs(0);
    return res - 1;
};