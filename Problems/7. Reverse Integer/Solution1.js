var reverse = function(x) {
    const INT_MAX = 2**31 - 1, INT_MIN = -1 * 2**31;
    let res = 0, tmp;
    while (x) {
        tmp = x % 10;
        if (x > 0 && res > Math.floor((INT_MAX - tmp) / 10)) return 0;
        if (x < 0 && res < Math.ceil((INT_MIN - tmp) / 10)) return 0;
        res = res * 10 + tmp;
        x = x > 0 ? Math.floor(x / 10) : Math.ceil(x / 10);
    }
    return res;
};