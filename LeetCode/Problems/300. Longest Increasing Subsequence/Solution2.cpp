// dp 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for(const auto& num: nums) {
            if (arr.size() == 0 || num > arr[arr.size()-1])  arr.push_back(num);
            else {
               int idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
               arr[idx] = num;
            }
        }
        return arr.size();
    }
};
