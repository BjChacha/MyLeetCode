// simulate
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        if (n == 1) return {1};
        int lo = 1, hi = n, i = 0;
        bool flipped = true;
        vector<int> res(n, 0);
        while (i < n - k) res[i++] = lo ++;
        while (i < n) {
            res[i++] = flipped ? hi -- : lo ++;
            flipped = !flipped;
        }
        return res;
    }
};
