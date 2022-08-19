// mono stack
var trap = function(height) {
    const stk = [];
    let res = 0;
    for (let i = 0; i < height.length; ++i) {
        while (stk.length && height[stk.at(-1)] <= height[i]) {
            const bot = height[stk.at(-1)];
            stk.pop();
            if (stk.length) {
                res += (i - stk.at(-1) - 1) * (Math.min(height[stk.at(-1)], height[i]) - bot);
            }
        }
        stk.push(i);
    }
    return res;
};
