// sort + binary insert
var lastStoneWeight = function(stones) {
    
    const binsert = function(x) {
        let l = 0, r = stones.length - 1, mid;
        while (l <= r) {
            mid = l + r >> 1;
            if (stones[mid] >= x) r = mid - 1;
            else if (stones[mid] < x) l = mid + 1;
        }
        return l;
    }
    
    stones.sort((x,y)=>x-y);
    while (stones.length > 1) {
        let [x, y] = stones.splice(stones.length - 2, 2);
        y -= x;
        if (y) {
            let i = binsert(y);
            stones.splice(i, 0, y);
        }
    }
    return stones.length ? stones[0] : 0;
};