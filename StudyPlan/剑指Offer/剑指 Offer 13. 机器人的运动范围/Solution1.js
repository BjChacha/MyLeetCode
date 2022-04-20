// bfs
var movingCount = function(m, n, k) {
    
    const getDigitSum = function(a, b) {
        let res = 0;
        while (a) res += a%10, a = Math.floor(a / 10);
        while (b) res += b%10, b = Math.floor(b / 10);
        return res;
    }
    
    const seen = Array(m).fill(0).map(()=>Array(n).fill(false));
    seen[0][0] = true;
    let cur = [[0, 0]];
    let nex = [];
    let res = 1;
    while (cur.length) {
        for (let pos of cur) {      
            if (pos[0] + 1  < m && !seen[pos[0]+1][pos[1]] && getDigitSum(pos[0] + 1, pos[1]) <= k) {
                ++res;
                seen[pos[0]+1][pos[1]] = true;
                nex.push([pos[0] + 1, pos[1]]);
            }
            if (pos[1] + 1  < n && !seen[pos[0]][pos[1]+1] && getDigitSum(pos[0], pos[1] + 1) <= k) {
                ++res;
                seen[pos[0]][pos[1]+1] = true;
                nex.push([pos[0], pos[1] + 1]);
            }
        }
        cur = nex;
        nex = [];
    }
    return res;
};