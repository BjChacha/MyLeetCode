// simulate
var generateMatrix = function(n) {
    const res = Array(n).fill(0).map(()=>Array(n).fill(0));
    let t = 0, l = 0, r = n -  1, b = n - 1;
    let x = 0, y = 0, e = 1;
    
    while (l <= r) {
        // to right
        while (y < r) res[x][y++] = e++;
        ++t

        // to bottom
        while (x < b) res[x++][y] = e++;
        --r;

        // to left
        while (y > l) res[x][y--] = e++;
        --b;

        // to top
        while (x > t) res[x--][y] = e++;
        ++l;
        
        // fill the lack
        res[x][y++] = e++;
    }
    return res;
};