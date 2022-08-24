// DP (2D LIS)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return b[1] < a[1];
        else return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> arr(n, -1);
        int lo, hi, mi, res = 0, h;
        for (int i = 0; i < n; ++i) {
            h = envelopes[i][1];
            lo = 0, hi = res;
            while (lo < hi) {
                mi = (lo + hi) >> 1;
                if (arr[mi] < h) lo = mi + 1;
                else hi = mi;
            }
            if (arr[lo] == -1) res ++;
            arr[lo] = h;
        }
        return res;
    }
};
