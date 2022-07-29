// iteration
var countVowelStrings = function(n) {
    const res = [1, 1, 1, 1, 1];
    while (--n) {
        for (let i = 1; i < 5; ++i) 
            res[i] += res[i-1];
    }
    return res.reduce((a, b) => a + b);
};