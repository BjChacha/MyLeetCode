// hash table + greedy
var isPossible = function(nums) {

    const numCnt = {};
    const seqCnt = {};

    for (const num of nums) numCnt[num] = (numCnt[num] ?? 0) + 1;

    for (const num of nums) {
        if (numCnt[num] === 0) continue;
        if (seqCnt[num-1] > 0) {
            seqCnt[num-1] --;
            seqCnt[num] = (seqCnt[num] ?? 0) + 1;
            numCnt[num] --;
        } else {
            if (!(numCnt[num+1] > 0 && numCnt[num+2] > 0)) return false;
            numCnt[num] --;
            numCnt[num+1] --;
            numCnt[num+2] --;
            seqCnt[num+2] = (seqCnt[num+2] ?? 0) + 1;
        }
    }
    return true;
    
};
