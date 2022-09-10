// recursion
class Solution {
private:
    void recursion(vector<vector<int>>& res, vector<int>& arr, int begin, int end) {
        if (begin == end) {
            res.push_back(arr);
        } else {
            for (int i = begin; i < end; ++i) {
                swap(arr[begin], arr[i]);
                recursion(res, arr, begin + 1, end);
                swap(arr[begin], arr[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        recursion(res, nums, 0, n);
        return res;
    }
};
