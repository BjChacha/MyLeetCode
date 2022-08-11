class Solution {
public:
    string reformat(string s) {
        int cc = 0, dc = 0, ci = 0, di = 0;
        string res = string(s.length(), ' ');
        for (const char& c: s) {
            if ('0' <= c && c <= '9') dc ++;
            else cc ++;
        }
        if (abs(dc - cc) > 1) return "";
        di = dc < cc;
        ci = dc >= cc;
        for (const char& c: s) {
            if ('0' <= c && c <= '9') {
                res[di] = c;
                di += 2;
            } else {
                res[ci] = c;
                ci += 2;
            }
        } 
        return res;
    }
};
