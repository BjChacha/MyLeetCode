// Hash table
var findSubstring = function(s, words) {
    const res = [];
    const counter = {};
    
    words.forEach((e) => {
        counter[e] = (counter[e] ?? 0) + 1;
    });
    
    for (let i = 0; i <= s.length - words.length * words[0].length; ++i) {
        if (s.substr(i, words[0].length) in counter) {
            const tmp = {...counter};
            let success = true;
            for (let j = i; j < i + words.length * words[0].length; j += words[0].length) {
                const ss = s.substr(j, words[0].length);
                if (!(ss in tmp) || tmp[ss] === 0) {
                    success = false;
                    break;
                }
                tmp[ss] --;
            }
            if (success) res.push(i);
        }
    }
    return res;
};
