// two pointers
var addStrings = function(num1, num2) {
    const code_0 = '0'.charCodeAt();
    
    let res = "";
    let p1 = num1.length - 1, p2 = num2.length - 1;
    let sum = 0, advan = 0;
    while (p1 >= 0 && p2 >= 0) {
        sum = (num1[p1].charCodeAt() - code_0) + (num2[p2].charCodeAt() - code_0) + advan;
        res = sum % 10 + res;
        advan = Math.floor(sum / 10);
        p1 --;
        p2 --;
    }
        while (p1 >= 0) {
        sum = num1[p1].charCodeAt() - code_0 + advan;
        res = sum % 10 + res;
        advan = Math.floor(sum / 10);
        p1 --;
    }
        while (p2 >= 0) {
        sum = num2[p2].charCodeAt() - code_0 + advan;
        res = sum % 10 + res;
        advan = Math.floor(sum / 10);
        p2 --;
    }
    if (advan > 0)
        res = advan + res;
    return res;
};