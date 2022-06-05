// stack
var longestValidParentheses = function(s) {
    let stk = [-1]
    let res = 0
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '(') stk.push(i)
        else {
            stk.pop()
            if (stk.length === 0) stk.push(i)
            else res = Math.max(res, i - stk[stk.length-1])
        }
    }
    return res
};