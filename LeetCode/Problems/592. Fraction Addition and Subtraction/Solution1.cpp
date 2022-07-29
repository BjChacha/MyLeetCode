// Simulation
class Solution {
private: 
    vector<string> split(const string &str, const char &delimiter) {
        auto idx = str.find(delimiter);
        return {str.substr(0, idx), str.substr(idx + 1, str.length() - idx - 1)};
    }
    
    int gcd(int a, int b) {
        if (b > a) return gcd(b, a);
        int t;
        while (b) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    
public:
    string fractionAddition(string expression) {
        int nRes = 0, dRes = 1;
        // process expression
        int start = 0, end = 0;
        bool slash = false;
        while (start < expression.length()) {
            // find the range of string that represent a single fraction
            while (end <= expression.length()) {
                if (slash && (expression[end] == '+' || expression[end] == '-' || end == expression.length())) break;
                else if (expression[end] == '/') slash = true;
                ++end;
            }
            
            // fraction calculation
            // get numerator and denmominator
            vector<string> nStrs = split(expression.substr(start, end - start), '/');
            int nCur = stoi(nStrs[0]), dCur = stoi(nStrs[1]);
            
            // using int will not overflow
            int nTmp = nCur * dRes + nRes * dCur, dTmp = dCur * dRes;
            int d = gcd(abs(nTmp), abs(dTmp));
            nRes = nTmp / d;
            dRes = dTmp / d;
            
            // reset status
            slash = false;
            start = end;
        }
        
        return to_string(nRes) + "/" + to_string(dRes);
    }
};