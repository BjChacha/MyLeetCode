// sort
class Solution {
private:
    int target;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        target = x;
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (abs(a - target) == abs(b - target)) return a < b;
            else return abs(a - target) < abs(b - target);
        });
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};
