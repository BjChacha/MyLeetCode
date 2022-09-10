// binary search + two pointer
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        int l = 0, r = n - 1, m;
        while (l < r) {
            m = (l + r) >> 1;
            if (arr[m] > x) r = m;
            else l = m + 1;
        }
        if (l - 1 >= 0 && abs(arr[l] - x) >= abs(arr[l-1] - x)) l --;
        r = l;
        while (r - l + 1 < k) {
            if (l - 1 >= 0 && r + 1 < n) {
                if (abs(arr[l-1] - x) <= abs(arr[r+1] - x)) l--;
                else r++;
            } else if (l - 1 >= 0) l--;
            else r++;
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
