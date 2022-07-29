var wordBreak = function(s, wordDict) {
    
    const dp = new Array(s.length+1).fill(false);
    dp[s.length] = true;
    for (let i = s.length - 1; i >= 0; --i) {
        for (let word of wordDict) {
            if (i + word.length <= s.length && dp[i+word.length] && s.substr(i, word.length) === word) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
};