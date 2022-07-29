// Math
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return (1 + nums.size()) * nums.size() / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};