var maxChunksToSorted = function(arr) {
    const n = arr.length;
    const leftMax = new Array(n).fill(arr[0]);
    const rightMin = new Array(n + 1);
    rightMin.splice(-1, 1, Infinity);
    let res = 0;

    for (let i = 1; i < n; ++i) leftMax[i] = Math.max(leftMax[i-1], arr[i]);
    for (let i = n - 1;  i >= 0; --i) rightMin[i] = Math.min(rightMin[i+1], arr[i]);

    for (let i = 0; i < n; ++i) {
        if (leftMax[i] <= rightMin[i+1]) res ++;
    }
    
    return res;
}
