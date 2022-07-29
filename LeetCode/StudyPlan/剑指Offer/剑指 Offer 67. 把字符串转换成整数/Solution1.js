// simulate
var strToInt = function(str) {
    const n = str.length;
    const INT_MAX = 2 ** 31 - 1;
    const INT_MIN = - (2 ** 31);
    let res = 0, sign = 1, i = 0, tmp;
    while (str[i] === ' ') ++i;
    if (str[i] === '-') {
        sign = -1; 
        ++i;
    } else if (str[i] === '+'){
        ++i;
    }

    while (i < n && str[i] >= '0' && str[i] <= '9') {
        tmp = (+str[i]) * sign;
        if (sign > 0 && (INT_MAX - tmp) / 10 < res) return INT_MAX;
        else if (sign < 0 && (INT_MIN - tmp) / 10 > res) return INT_MIN;
        else res = res * 10 + tmp;
        ++i;
    }
    return res;
};