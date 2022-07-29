// dp
var translateNum = function(num) {

    const dp = function(num) {
        if (!map.has(num)) {
            if (Math.floor(num / 10) === 0) map.set(num, 1);
            else if (9 < num % 100 && num % 100 < 26) map.set(num, translateNum(Math.floor(num / 10)) + translateNum(Math.floor(num / 100)));
            else map.set(num, translateNum(Math.floor(num / 10)));
        }
        return map.get(num);
    }
    
    const map = new Map();
    dp(num);
    return map.get(num);
};