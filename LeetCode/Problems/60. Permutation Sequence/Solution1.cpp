// next permutation
class Solution {
private:
    void step(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] > arr[i+1]) --i;
        int j = arr.size() - 1;
        if (i >= 0) {
            while (arr[j] < arr[i]) --j;
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin() + i + 1, arr.end());
   }
public:
    string getPermutation(int n, int k) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) arr[i] = i + 1;
        while (--k) step(arr);
        string res = "";
        for (const auto& a: arr) res += to_string(a);
        return res;
    }
};
