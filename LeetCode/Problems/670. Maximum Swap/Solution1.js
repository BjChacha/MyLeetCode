var maximumSwap = function(num) {
    const charArray = [...'' + num];
    const n = charArray.length;
    let maxIdx = n - 1;
    let idx1 = -1, idx2 = -1;
    for (let i = n - 1; i >= 0; i--) {
        if (charArray[i] > charArray[maxIdx]) {
            maxIdx = i;
        } else if (charArray[i] < charArray[maxIdx]) {
            idx1 = i;
            idx2 = maxIdx;
        }
    }
    if (idx1 >= 0) {
        swap(charArray, idx1, idx2);
        return parseInt(charArray.join(''));
    } else {
        return num;
    }
}

const swap = (charArray, i, j) => {
    const temp = charArray[i];
    charArray[i] = charArray[j];
    charArray[j] = temp;
};
