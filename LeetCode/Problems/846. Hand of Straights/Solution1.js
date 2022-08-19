var isNStraightHand = function(hand, groupSize) {
    const n = hand.length;
    if (n % groupSize) return false;
    
    const counter = {};
    for (const num of hand) counter[num] = (counter[num] ?? 0) + 1;
    hand.sort((a, b) => a - b);
    for (const num of hand) {
        if (counter[num] === 0) continue;
        for (let i = 0; i < groupSize; ++i) {
            if (!counter[num+i] > 0) return false;
            counter[num+i] --;
        }
    }
    return true;
};
