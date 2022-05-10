// dfs
var letterCombinations = function(digits) {
    
    let num2cha = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz',
    };
    
    res = [];
    
    const dfs = function(i, s) {
        if (i === digits.length) {
            if (s) res.push(s);
        } else {
            for (let c of num2cha[digits[i]]) {
                dfs(i + 1, s + c);
            }
        }
    }
    
    dfs(0, "");
    return res;
};