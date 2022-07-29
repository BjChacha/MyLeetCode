// finite-state machine
var isNumber = function(s) {
    s = s.trim();
    let isSign = false, isDot = false, isExp = false, isNum = false;

    for (let c of s) {
        if (c === '+' || c === '-') {
            if (!isSign) isSign = true;
            else return false;
        } else if (c === '.') {
            if (!isDot) {
                isDot = true;
                isSign = true;
            } else return false;

        } else if (c === 'e' || c === 'E') {
            if (isNum && !isExp) {
                isExp = true;
                isSign = false;
                isDot = true;
                isNum = false;
            } else return false;
        } else if ('0' <= c && c <= '9') {
            isSign = true;
            isNum = true;
        } else {
            return false;
        }
    }
    return isNum;
};