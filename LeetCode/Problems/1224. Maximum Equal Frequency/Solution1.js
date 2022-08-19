// hash-table
var maxEqualFreq = function(nums) {
    const cnt = new Map();
    const ccnt = new Map();
    let res = 1;
    for (const [i, num] of nums.entries()) {
        if (!cnt.has(num)) {
            cnt.set(num, 1);
            ccnt.set(1, (ccnt.get(1) || 0) + 1);
        } else {
            const key = cnt.get(num);
            if (ccnt.get(key) === 1) ccnt.delete(key);
            else ccnt.set(key, ccnt.get(key) - 1);

            cnt.set(num, key + 1);
            ccnt.set(key + 1, (ccnt.get(key + 1) || 0) + 1);
        }

        // 拆分开，提高可读性
        // 1. 如果只出现一种元素
        if (cnt.size === 1)
            res = i + 1;
        // 2. 如果每个元素都只出现一次
        else if (ccnt.size === 1 && ccnt.get(1) > 0)
            res = i + 1;
        // 3. 出现频率最多只有两种值，要么只有一个元素出现一次，要么只有一个元素出现较多次
        else if (ccnt.size === 2) {
            if (ccnt.get(1) === 1) res = i + 1;
            else {
                let [a, b] = Array.from(ccnt.keys());
                if (a > b) [a, b] = [b, a];
                if (b - a === 1 && ccnt.get(b) === 1) res = i + 1;
            }
        }
    }
    return res;
};
