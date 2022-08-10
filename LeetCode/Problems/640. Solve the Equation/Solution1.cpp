// simulate
class Solution {
public:
    string solveEquation(string equation) {
        int ie = find(equation.begin(), equation.end(), '=') - equation.begin();
        string el = equation.substr(0, ie);
        string er = equation.substr(ie + 1, equation.length() - el.length() - 1);
        // count of x, count of const, sign and temp counter
        int cx = 0, cc = 0, sign = 1, tmp = 0;
        // if no number in front of x, default equal to 1
        bool hasNumber = false;
        for (const auto& c: el) {
            if (c == '-') {
                cc += sign * tmp; 
                tmp = 0;
                sign = -1;
                hasNumber = false;
            } else if (c == '+') {
                cc += sign * tmp;
                tmp = 0;
                sign = 1;
                hasNumber = false;
            } else if (c == 'x') {
                if (!hasNumber) tmp = 1;
                cx += sign * tmp;
                tmp = 0;
                hasNumber = false;
            } else {
                hasNumber = true;
                tmp = tmp * 10 + (c - '0');
            }
        }
        if (tmp > 0) {
            cc += sign * tmp;
            tmp = 0;
        }
        
        sign = 1;
        hasNumber = false;
        for (const auto& c: er) {
            if (c == '-') {
                cc -= sign * tmp; 
                tmp = 0;
                sign = -1;
                hasNumber = false;
            } else if (c == '+') {
                cc -= sign * tmp;
                tmp = 0;
                sign = 1;
                hasNumber = false;
            } else if (c == 'x') {
                if (!hasNumber) tmp = 1;
                cx -= sign * tmp;
                tmp = 0;
                hasNumber = false;
            } else {
                hasNumber = true;
                tmp = tmp * 10 + (c - '0');
            }
        }
        if (tmp > 0) {
            cc -= sign * tmp;
            tmp = 0;
        }
        
        if (cx == 0) return cc == 0 ? "Infinite solutions" : "No solution";
        else return "x=" + to_string(-cc / cx);
    }
};
