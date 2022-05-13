// dfs + memo
var wordBreak = function(s, wordDict) {
    
    const startswith = function(i, t) {
        if (t.length > s.length - i) return false;
        for (let j = 0; j < t.length; ++j) {
            if (s[j+i] !== t[j]) return false;
        }
        return true;
    }

    const dfs = function(i) {
        console.log(i);
        if (i === s.length) return true;
        if (memo[i]) {
            for (let j = 0; j < wordDict.length; ++j) {
                if (startswith(i, wordDict[j])) {
                    if (dfs(i + wordDict[j].length)) return true;
                }
            }
            memo[i] = false;
        }
        return false
    }
    const memo = new Array(s.length).fill(true);
    return dfs(0);
};