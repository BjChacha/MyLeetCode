// two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return {};

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l, r, m, sum;
        
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            l = i + 1, r = n - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }
            }
        }
        return res;
    }
};
